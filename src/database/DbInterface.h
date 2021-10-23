#ifndef SRC_DBINTERFACE_H
#define SRC_DBINTERFACE_H

#include <sqlite3.h>
#include <string>

class DbInterface {
public:
    DbInterface(const char *db_filename);
    ~DbInterface();
    std::string get_password(const std::string &name) const;
    bool insert_password(const std::string &name, const std::string &pw) const;

private:
    sqlite3 *db;
};

#endif //SRC_DBINTERFACE_H
