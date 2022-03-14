#ifndef SRC_ABSTRACTSQLDATABASEMOCK_H
#define SRC_ABSTRACTSQLDATABASEMOCK_H

#include "../../../adapters/database/AbstractSqlDatabase.h"
#include <set>
#include <gmock/gmock.h>

using namespace DDD;

class AbstractSqlDatabaseMock : public Adapters::Database::AbstractSqlDatabase
{
public:
    MOCK_METHOD((std::pair<std::set<DDD::Entities::Entry>, std::string>), executeSql, (const std::string& statement), (const, override));
};

#endif //SRC_ABSTRACTSQLDATABASEMOCK_H
