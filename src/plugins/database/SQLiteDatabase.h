#ifndef SRC_SQLITEDATABASE_H
#define SRC_SQLITEDATABASE_H

#include <sqlite3.h>
#include <string>
#include "../../application/Database.h"

namespace Plugins::Database
{
class SQLiteDatabase : public DatabaseInterface::Database
    {
    public:
        SQLiteDatabase(const char *db_filename);
        ~SQLiteDatabase();
        std::pair<std::string, std::string> execute_sql(const std::string &statement) const;
    private:
        sqlite3 *db;
    };
} // Plugins::Database

#endif //SRC_SQLITEDATABASE_H
