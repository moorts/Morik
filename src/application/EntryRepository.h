#ifndef SRC_ENTRYREPOSITORY_H
#define SRC_ENTRYREPOSITORY_H

#include <set>
#include "AbstractDatabaseInterface.h"
#include "Entry.h"
#include "EntryId.h"

namespace DDD::Repositories {
    class EntryRepository {
    public:
        EntryRepository(const AbstractDatabaseInterface* const dbInterface) { this->dbInterface = dbInterface; }
        Entities::Entry getEntry(ValueObjects::EntryId entryId) const;
        std::set<Entities::Entry> find(ValueObjects::EntryName entryName) const;
        void store(const Entities::Entry &entry) const;
        void remove(const Entities::Entry &entry) const;
        void modifyEntry(const Entities::Entry &entry, const ValueObjects::EntryName &newEntryName) const;
        void modifyEntry(const Entities::Entry &entry, const ValueObjects::Login &newLogin) const;
        void modifyEntry(const Entities::Entry &entry, const ValueObjects::EncryptedPassword &newEncryptedPassword) const;
        ValueObjects::EntryId nextId() const;
    private:
        const AbstractDatabaseInterface* dbInterface;
    };
} // DDD::Repositories

#endif //SRC_ENTRYREPOSITORY_H
