#ifndef SRC_SQLITEDATABASE_H
#define SRC_SQLITEDATABASE_H

#include <sqlite3.h>
#include <string>
#include "../../application/AbstractDatabase.h"

namespace Plugins::Database
{
class SQLiteDatabase : public DatabaseInterface::AbstractDatabase
    {
    public:
        SQLiteDatabase(const char* dbFilename);
        ~SQLiteDatabase();
        std::pair<std::set<DDD::Entities::Entry>, std::string> executeSql(const std::string& statement) const;
    private:
        sqlite3 *db;
    };
} // Plugins::AbstractDatabase

#endif //SRC_SQLITEDATABASE_H
