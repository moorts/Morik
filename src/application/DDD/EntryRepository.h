#ifndef SRC_ENTRYREPOSITORY_H
#define SRC_ENTRYREPOSITORY_H

#include <set>
#include "../DbInterface.h"
#include "Entry.h"
#include "EntryId.h"

namespace DDD::Repositories {
    class EntryRepository {
    public:
        EntryRepository(const DatabaseInterface::DbInterface &dbInterface) : dbInterface(dbInterface) {}
        void store(const Entities::Entry &entry);
        Entities::Entry getEntry(ValueObjects::EntryId id);
        std::set<Entities::Entry> find(ValueObjects::EntryName name);
        ValueObjects::EntryId nextId();
    private:
        DatabaseInterface::DbInterface dbInterface;
    };
} // DDD::Repositories

#endif //SRC_ENTRYREPOSITORY_H
