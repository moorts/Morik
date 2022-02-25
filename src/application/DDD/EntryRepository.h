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
        Entities::Entry getEntry(ValueObjects::EntryId entryId) const;
        std::set<Entities::Entry> find(ValueObjects::EntryName entryName) const;
        void store(const Entities::Entry &entry) const;
        void remove(const Entities::Entry &entry) const;
        void modifyEntryName(const Entities::Entry &entry, const ValueObjects::EntryName &newEntryName) const;
        void modifyLogin(const Entities::Entry &entry, const ValueObjects::Login &newLogin) const;
        void modifyEncryptedPassword(const Entities::Entry &entry, const ValueObjects::EncryptedPassword &newEncryptedPassword) const;
        ValueObjects::EntryId nextId() const;
    private:
        DatabaseInterface::DbInterface dbInterface;
    };
} // DDD::Repositories

#endif //SRC_ENTRYREPOSITORY_H
