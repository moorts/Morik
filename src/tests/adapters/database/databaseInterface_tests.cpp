#include <gtest/gtest.h>
#include "AbstractSqlDatabaseMock.h"
#include "../../../adapters/database/DatabaseInterface.h"

TEST(GetEntry, AdapterTests) {
    AbstractSqlDatabaseMock abstractDbMock;
    Adapters::Database::DatabaseInterface dbInterface(&abstractDbMock);

    Entities::Entry entry = dbInterface.getEntry(ValueObjects::EntryId(1));

    EXPECT_EQ("TestPassword", entry.encryptedPassword.getString());
}

TEST(GetInvalidEntry, AdapterTests) {
    AbstractSqlDatabaseMock abstractDbMock;
    Adapters::Database::DatabaseInterface dbInterface(&abstractDbMock);

    ValueObjects::EntryId invalidId(2);
    EXPECT_THROW(dbInterface.getEntry(invalidId), std::domain_error);
}