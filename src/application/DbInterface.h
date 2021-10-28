#ifndef SRC_DBINTERFACE_H
#define SRC_DBINTERFACE_H

#include <string>
#include "AbstractDatabase.h"

namespace DatabaseInterface
{
    class DbInterface
    {
    public:
        DbInterface(const AbstractDatabase *const database) { db = database; };
        std::string get_password(const std::string &name) const;
        bool insert_password(const std::string &name, const std::string &pw) const;
    private:
        const AbstractDatabase *db;
    };
} // DatabaseInterface

#endif //SRC_DBINTERFACE_H
