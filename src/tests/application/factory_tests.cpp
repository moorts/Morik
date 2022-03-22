#include <gtest/gtest.h>
#include "../../application/EntryFactory.h"

TEST(CreateEntry, DDDTests) {
    Entities::Entry actual = Factories::EntryFactory::createEntry(1, "TestEntry", "TestLogin", "SomeEncryptedPassword");
    Entities::Entry expected(ValueObjects::EntryId(1), ValueObjects::EntryName("TestEntry"), ValueObjects::Login("TestLogin"), ValueObjects::EncryptedPassword("SomeEncryptedPassword"));

    EXPECT_EQ(expected, actual);
}

TEST(CreateWrongEntry, DDDTests) {
    Entities::Entry actual = Factories::EntryFactory::createEntry(2, "TestEntry2", "TestLogin", "SomeEncryptedPassword");
    Entities::Entry notExpected(ValueObjects::EntryId(1), ValueObjects::EntryName("TestEntry"), ValueObjects::Login("TestLogin"), ValueObjects::EncryptedPassword("SomeEncryptedPassword"));

    EXPECT_NE(notExpected, actual);
}
