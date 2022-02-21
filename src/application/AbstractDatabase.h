#ifndef SRC_ABSTRACTDATABASE_H
#define SRC_ABSTRACTDATABASE_H

#include <vector>

namespace DatabaseInterface
{
    class AbstractDatabase
    {
    public:
        virtual std::pair<std::vector<std::string>, std::string> executeSql(const std::string &statement) const = 0;
    };
} // DatabaseInterface

#endif //SRC_ABSTRACTDATABASE_H
