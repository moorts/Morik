#ifndef SRC_ABSTRACTDATABASEINTERFACE_H
#define SRC_ABSTRACTDATABASEINTERFACE_H

#include <string>
#include <set>
#include "../adapters/database/AbstractSqlDatabase.h"
#include "DatabaseColumn.h"

class AbstractDatabaseInterface {
public:
    virtual DDD::Entities::Entry getEntry(const DDD::ValueObjects::EntryId &entryId) const = 0;
    virtual std::set<DDD::Entities::Entry> getEntries(const DDD::ValueObjects::EntryName &entryName) const = 0;
    virtual std::set<DDD::Entities::Entry> getAllEntries() const = 0;
    virtual bool insertEntry(const DDD::Entities::Entry &entry) const = 0;
    virtual bool removeEntry(const DDD::ValueObjects::EntryId &entryId) const = 0;
    virtual bool
    modifyEntry(const DDD::ValueObjects::EntryId &entryId, const DatabaseColumn &column, const std::string &newValue) const = 0;
};

#endif //SRC_ABSTRACTDATABASEINTERFACE_H
