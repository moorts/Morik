#ifndef SRC_DATABASE_H
#define SRC_DATABASE_H

namespace DatabaseInterface
{
    class Database
    {
    public:
        virtual std::pair<std::string, std::string> execute_sql(const std::string &statement) const = 0;
    };
} // DatabaseInterface

#endif //SRC_DATABASE_H
