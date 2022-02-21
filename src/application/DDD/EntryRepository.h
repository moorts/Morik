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
        void store(const Entry &entry);
        Entry getEntry(EntryId id);
        std::set<Entry> find(EntryName name);
        EntryId nextId();
    private:
        DatabaseInterface::DbInterface dbInterface;
    };
} // DDD::Repositories

#endif //SRC_ENTRYREPOSITORY_H
