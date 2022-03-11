#include <gtest/gtest.h>
#include "AbstractSqlDatabaseMock.h"
#include "../../../adapters/database/DatabaseInterface.h"

using testing::Return;

TEST(GetEntry, AdapterTests) {
    AbstractSqlDatabaseMock abstractDbMock;
    std::set<DDD::Entities::Entry> nonEmptyEntrySet{Entities::Entry(ValueObjects::EntryId(1), ValueObjects::EntryName("TestEntry"), ValueObjects::Login("TestLogin"), ValueObjects::EncryptedPassword("TestPassword"))};
    EXPECT_CALL(abstractDbMock, executeSql("SELECT * FROM passwords WHERE EntryId = \"1\";")).Times(1).WillOnce(Return(std::make_pair(nonEmptyEntrySet, "")));
    Adapters::Database::DatabaseInterface dbInterface(&abstractDbMock);

    Entities::Entry entry = dbInterface.getEntry(ValueObjects::EntryId(1));

    EXPECT_EQ("TestPassword", entry.encryptedPassword.getString());
}

TEST(GetInvalidEntry, AdapterTests) {
    AbstractSqlDatabaseMock abstractDbMock;
    std::set<DDD::Entities::Entry> emptyEntrySet;
    EXPECT_CALL(abstractDbMock, executeSql("SELECT * FROM passwords WHERE EntryId = \"2\";")).Times(1).WillOnce(Return(std::make_pair(emptyEntrySet, "")));
    Adapters::Database::DatabaseInterface dbInterface(&abstractDbMock);

    ValueObjects::EntryId invalidId(2);
    EXPECT_THROW(dbInterface.getEntry(invalidId), std::domain_error);
}