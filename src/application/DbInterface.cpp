#include "DbInterface.h"

using namespace DatabaseInterface;

std::string DbInterface::get_password(const std::string &name) const
{
    std::string sql = "SELECT pw FROM passwords WHERE name = \"" + name + "\";";
    auto [value, error] = db->execute_sql(sql);
    return value;
}

bool DbInterface::insert_password(const std::string &name, const std::string &pw) const
{
    std::string sql = "INSERT INTO passwords VALUES(\"" + name + "\",\"" + pw +"\");";
    auto [value, error] = db->execute_sql(sql);
    if (!error.empty())
    {
        return false;
    }
    return true;
}
