#include <gtest/gtest.h>
#include "AbstractDatabaseInterfaceMock.h"
#include "../../application/EntryRepository.h"

TEST(GetEntry, DDDTests) {
    AbstractDatabaseInterfaceMock mock;
    Entities::Entry expected(ValueObjects::EntryId(1), ValueObjects::EntryName("TestEntry"), ValueObjects::Login("TestLogin"), ValueObjects::EncryptedPassword("TestPassword"));
    EXPECT_CALL(mock, getEntry(ValueObjects::EntryId(1))).Times(1).WillOnce(Return(expected));

    Repositories::EntryRepository repo(&mock);

    Entities::Entry actual = repo.getEntry(ValueObjects::EntryId(1));

    EXPECT_EQ(expected, actual);
}

TEST(FindWithName, DDDTests) {
    AbstractDatabaseInterfaceMock mock;
    ValueObjects::EntryName entryName("TestEntry");
    Entities::Entry expected0(ValueObjects::EntryId(1), entryName, ValueObjects::Login("TestLogin"), ValueObjects::EncryptedPassword("SomeEncryptedPassword"));
    Entities::Entry expected1(ValueObjects::EntryId(2), entryName, ValueObjects::Login("AnotherTestLogin"), ValueObjects::EncryptedPassword("AnotherEncryptedPassword"));
    std::set<Entities::Entry> expectedEntries;
    expectedEntries.emplace(expected0);
    expectedEntries.emplace(expected1);
    EXPECT_CALL(mock, getEntries(ValueObjects::EntryName("TestEntry"))).Times(1).WillOnce(Return(expectedEntries));

    Repositories::EntryRepository repo(&mock);
    std::set<Entities::Entry> actualEntries = repo.find(ValueObjects::EntryName("TestEntry"));

    EXPECT_EQ(2, actualEntries.size());
    EXPECT_NE(actualEntries.end(), actualEntries.find(expected0));
    EXPECT_NE(actualEntries.end(), actualEntries.find(expected1));
}
