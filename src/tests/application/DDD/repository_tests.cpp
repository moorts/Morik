#include <gtest/gtest.h>
#include "AbstractDatabaseInterfaceMock.h"
#include "../../../application/DDD/EntryRepository.h"

TEST(GetEntry, DDDTests) {
    AbstractDatabaseInterfaceMock mock;
    Repositories::EntryRepository repo(&mock);

    Entities::Entry expected(ValueObjects::EntryId(1), ValueObjects::EntryName("TestEntry"), ValueObjects::Login("TestLogin"), ValueObjects::EncryptedPassword("SomeEncryptedPassword"));
    Entities::Entry actual = repo.getEntry(ValueObjects::EntryId(1));

    EXPECT_EQ(expected, actual);
}

TEST(FindWithName, DDDTests) {
    AbstractDatabaseInterfaceMock mock;
    Repositories::EntryRepository repo(&mock);

    EXPECT_EQ(2, repo.find(ValueObjects::EntryName("TestEntry")).size());
}
