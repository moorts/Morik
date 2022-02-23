#ifndef SRC_ABSTRACTDATABASE_H
#define SRC_ABSTRACTDATABASE_H

#include <set>
#include "DDD/Entry.h"

namespace DatabaseInterface
{
    class AbstractDatabase
    {
    public:
        virtual std::pair<std::set<DDD::Entities::Entry>, std::string> executeSql(const std::string &statement) const = 0;
    };
} // DatabaseInterface

#endif //SRC_ABSTRACTDATABASE_H
