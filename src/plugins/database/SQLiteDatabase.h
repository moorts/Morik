#ifndef SRC_SQLITEDATABASE_H
#define SRC_SQLITEDATABASE_H

#include <sqlite3.h>
#include <string>
#include "../../adapters/database/AbstractSqlDatabase.h"

namespace Plugins::Database
{
class SQLiteDatabase : public Adapters::Database::AbstractSqlDatabase
    {
    public:
        SQLiteDatabase(const char* dbFilename);
        ~SQLiteDatabase();
        std::pair<std::set<DDD::Entities::Entry>, std::string> executeSql(const std::string& statement) const;
    private:
        sqlite3 *db;
    };
} // Plugins::AbstractSqlDatabase

#endif //SRC_SQLITEDATABASE_H
