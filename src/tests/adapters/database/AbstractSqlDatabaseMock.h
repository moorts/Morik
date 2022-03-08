#ifndef SRC_ABSTRACTSQLDATABASEMOCK_H
#define SRC_ABSTRACTSQLDATABASEMOCK_H

#include "../../../adapters/database/AbstractSqlDatabase.h"
#include <set>

using namespace DDD;

class AbstractSqlDatabaseMock : public Adapters::Database::AbstractSqlDatabase
{
public:
    std::pair<std::set<DDD::Entities::Entry>, std::string> executeSql(const std::string& statement) const override
    {
        std::set<Entities::Entry> returnSet;
        Entities::Entry testEntry(ValueObjects::EntryId(1), ValueObjects::EntryName("TestEntry"), ValueObjects::Login("TestLogin"), ValueObjects::EncryptedPassword("TestPassword"));
        if (statement == "SELECT * FROM passwords WHERE EntryId = \"1\";")
            returnSet.emplace(testEntry);
        return std::make_pair(returnSet, "");
    }
};

#endif //SRC_ABSTRACTSQLDATABASEMOCK_H
