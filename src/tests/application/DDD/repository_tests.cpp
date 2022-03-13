#include <gtest/gtest.h>
#include "AbstractDatabaseInterfaceMock.h"
#include "../../../application/DDD/EntryRepository.h"

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
    std::set<Entities::Entry> entries;
    ValueObjects::EntryName entryName("TestEntry");
    entries.emplace(ValueObjects::EntryId(1), entryName, ValueObjects::Login("TestLogin"), ValueObjects::EncryptedPassword("SomeEncryptedPassword"));
    entries.emplace(ValueObjects::EntryId(2), entryName, ValueObjects::Login("AnotherTestLogin"), ValueObjects::EncryptedPassword("AnotherEncryptedPassword"));
    EXPECT_CALL(mock, getEntries(ValueObjects::EntryName("TestEntry"))).Times(1).WillOnce(Return(entries));

    Repositories::EntryRepository repo(&mock);

    EXPECT_EQ(2, repo.find(ValueObjects::EntryName("TestEntry")).size());
}
