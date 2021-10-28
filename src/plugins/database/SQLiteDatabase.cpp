#include "SQLiteDatabase.h"
#include <iostream>

using namespace Plugins::Database;

SQLiteDatabase::SQLiteDatabase(const char *db_filename)
{
    int returnCode = sqlite3_open(db_filename, &db);
    if (returnCode)
    {
        std::cout << "Can't open database" << std::endl;
    }
}

SQLiteDatabase::~SQLiteDatabase()
{
    sqlite3_close(db);
}

std::pair<std::string, std::string> SQLiteDatabase::execute_sql(const std::string &statement) const
{
    auto callback = [](void* data, int argc, char** argv, char** azColName)
    {
        auto pw = static_cast<std::string*>(data);
        *pw = argv[0];
        return 0;
    };
    std::string returnValue;
    char* errMsg;
    int returnCode = sqlite3_exec(db, statement.c_str(), callback, &returnValue, &errMsg);
    if (returnCode != SQLITE_OK) {
        std::cout << "SQL error: " << errMsg << std::endl;
    }
    return std::make_pair(returnValue, !errMsg ? "" : std::string(errMsg));
}
