#include "DbInterface.h"
#include <iostream>

DbInterface::DbInterface(const char *db_filename)
{
    int returnCode = sqlite3_open(db_filename, &db);
    if (returnCode)
    {
        std::cout << "Can't open database" << std::endl;
    }
}

DbInterface::~DbInterface()
{
    sqlite3_close(db);
}

std::string DbInterface::get_password(const std::string &name) const
{
    auto callback = [](void* data, int argc, char** argv, char** azColName)
    {
        auto pw = static_cast<std::string*>(data);
        *pw = argv[0];
        return 0;
    };
    std::string sql = "SELECT pw FROM passwords WHERE name = \"" + name + "\";";
    std::string pw;
    char* errMsg;
    int returnCode = sqlite3_exec(db, sql.c_str(), callback, &pw, &errMsg);
    if (returnCode != SQLITE_OK) {
        std::cout << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return "";
    }
    return pw;
}

bool DbInterface::insert_password(const std::string &name, const std::string &pw) const
{
    std::string sql = "INSERT INTO passwords VALUES(\"" + name + "\",\"" + pw +"\");";
    char* errMsg;
    int returnCode = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
    if (returnCode != SQLITE_OK) {
        std::cout << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}
