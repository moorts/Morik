#ifndef SRC_DBINTERFACE_H
#define SRC_DBINTERFACE_H

#include <string>
#include <set>
#include "AbstractDatabase.h"
#include "DatabaseColumn.h"

namespace DatabaseInterface
{
    class DbInterface
    {
    public:
        DbInterface(const AbstractDatabase *const database) { db = database; };
        DDD::Entities::Entry getEntry(const DDD::ValueObjects::EntryId &entryId) const;
        std::set<DDD::Entities::Entry> getEntries(const DDD::ValueObjects::EntryName &entryName) const;
        std::set<DDD::Entities::Entry> getAllEntries() const;
        bool insertEntry(const DDD::Entities::Entry &entry) const;
        bool removeEntry(const DDD::ValueObjects::EntryId &entryId) const;
        bool modifyEntry(const DDD::ValueObjects::EntryId &entryId, const DatabaseColumn &column, const std::string &newValue) const;
    private:
        const AbstractDatabase *db;
    };
} // DatabaseInterface

#endif //SRC_DBINTERFACE_H
