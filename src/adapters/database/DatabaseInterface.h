#ifndef SRC_DATABASEINTERFACE_H
#define SRC_DATABASEINTERFACE_H

#include <string>
#include <set>
#include "../../application/AbstractDatabaseInterface.h"
#include "AbstractSqlDatabase.h"
#include "../../application/DatabaseColumn.h"

namespace Adapters::Database
{
    class DatabaseInterface : public AbstractDatabaseInterface
    {
    public:
        DatabaseInterface(const AbstractSqlDatabase *const database) { db = database; };
        DDD::Entities::Entry getEntry(const DDD::ValueObjects::EntryId &entryId) const;
        std::set<DDD::Entities::Entry> getEntries(const DDD::ValueObjects::EntryName &entryName) const;
        std::set<DDD::Entities::Entry> getAllEntries() const;
        bool insertEntry(const DDD::Entities::Entry &entry) const;
        bool removeEntry(const DDD::ValueObjects::EntryId &entryId) const;
        bool modifyEntry(const DDD::ValueObjects::EntryId &entryId, const DatabaseColumn &column, const std::string &newValue) const;
    private:
        bool performErrorCheck(std::string errorString) const;
        const AbstractSqlDatabase *db;
    };
} // Adapters::Database

#endif //SRC_DATABASEINTERFACE_H
