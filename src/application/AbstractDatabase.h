#ifndef SRC_ABSTRACTDATABASE_H
#define SRC_ABSTRACTDATABASE_H

namespace DatabaseInterface
{
    class AbstractDatabase
    {
    public:
        virtual std::pair<std::string, std::string> execute_sql(const std::string &statement) const = 0;
    };
} // DatabaseInterface

#endif //SRC_ABSTRACTDATABASE_H
