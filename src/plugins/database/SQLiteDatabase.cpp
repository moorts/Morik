#include "SQLiteDatabase.h"
#include <iostream>
#include "../../application/EntryFactory.h"

using namespace Plugins::Database;
using namespace DDD::Entities;

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

std::pair<std::set<Entry>, std::string> SQLiteDatabase::executeSql(const std::string& statement) const
{
    auto callback = [](void* data, int argc, char** argv, char** azColName)
    {
        auto returnValues = static_cast<std::set<Entry>*>(data);
        unsigned int id;
        std::string entryNameString;
        std::string loginString;
        std::string encryptedPasswordString;
        for (int i = 0; i < argc; ++i)
        {
            std::string colName = azColName[i];
            if (colName == "EntryId")
                id = atoi(argv[i]);
            else if (colName == "EntryName")
                entryNameString = argv[i];
            else if (colName == "Login")
            {
                if (argv[i])
                    loginString = argv[i];
            }
            else if (colName == "EncryptedPassword")
                encryptedPasswordString = argv[i];
        }
        Entry entry = DDD::Factories::EntryFactory::createEntry(id, entryNameString, loginString, encryptedPasswordString);
        returnValues->emplace(entry);
        return 0;
    };
    std::set<Entry> returnValues;
    char* errMsg;
    int returnCode = sqlite3_exec(db, statement.c_str(), callback, &returnValues, &errMsg);
    if (returnCode != SQLITE_OK) {
        std::cout << "SQL error: " << errMsg << std::endl;
    }

    return std::make_pair(returnValues, !errMsg ? "" : std::string(errMsg));
}
