#ifndef SRC_ABSTRACTSQLDATABASE_H
#define SRC_ABSTRACTSQLDATABASE_H

#include <set>
#include "../../application/Entry.h"

namespace Adapters::Database
{
    class AbstractSqlDatabase
    {
    public:
        virtual std::pair<std::set<DDD::Entities::Entry>, std::string> executeSql(const std::string &statement) const = 0;
    };
} // Adapters::Database

#endif //SRC_ABSTRACTSQLDATABASE_H
