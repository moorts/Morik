#include "SQLiteDatabase.h"
#include <iostream>

using namespace Plugins::Database;

SQLiteDatabase::SQLiteDatabase(const char* dbFilename)
{
    int returnCode = sqlite3_open(dbFilename, &db);
    if (returnCode)
    {
        std::cout << "Can't open database" << std::endl;
    }
}

SQLiteDatabase::~SQLiteDatabase()
{
    sqlite3_close(db);
}

std::pair<std::vector<std::string>, std::string> SQLiteDatabase::executeSql(const std::string& statement) const
{
    struct dbDataSet_t
    {
        unsigned int id;
        std::string name;
        std::string username;
        std::string pw;
    };
    auto callback = [](void* data, int argc, char** argv, char** azColName)
    {
        auto returnValues = static_cast<std::vector<dbDataSet_t>*>(data);
        dbDataSet_t dbDataSet;
        for (int i = 0; i < argc; ++i)
        {
            std::string colName = azColName[i];
            if (colName == "id")
                dbDataSet.id = atoi(argv[i]);
            else if (colName == "name")
                dbDataSet.name = argv[i];
            else if (colName == "username")
                dbDataSet.username = argv[i];
            else if (colName == "password")
                dbDataSet.pw = argv[i];
        }
        returnValues->emplace_back(dbDataSet);
        return 0;
    };
    std::vector<dbDataSet_t> returnValues;
    char* errMsg;
    int returnCode = sqlite3_exec(db, statement.c_str(), callback, &returnValues, &errMsg);
    if (returnCode != SQLITE_OK) {
        std::cout << "SQL error: " << errMsg << std::endl;
    }

    // temporary test code
    std::vector<std::string> passwords;
    for (dbDataSet_t dataSet : returnValues)
    {
        passwords.emplace_back(dataSet.pw);
    }

    return std::make_pair(passwords, !errMsg ? "" : std::string(errMsg));
}
