#include <gtest/gtest.h>
#include "AbstractSqlDatabaseMock.h"
#include "../../../adapters/database/DatabaseInterface.h"

TEST(GetEntryTest, BasicAssertions) {
    AbstractSqlDatabaseMock abstractDbMock;
    Adapters::Database::DatabaseInterface dbInterface(&abstractDbMock);

    Entities::Entry entry = dbInterface.getEntry(ValueObjects::EntryId(1));

    EXPECT_EQ("TestPassword", entry.encryptedPassword.getString());
}