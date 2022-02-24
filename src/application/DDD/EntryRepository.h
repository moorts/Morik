#ifndef SRC_ENTRYREPOSITORY_H
#define SRC_ENTRYREPOSITORY_H

#include <set>
#include <memory>
#include "../DbInterface.h"
#include "Entry.h"
#include "EntryId.h"

namespace DDD::Repositories {
    class EntryRepository final {
    public:
        static void createInstance(const DatabaseInterface::DbInterface &dbInterface);
        static EntryRepository* getInstance();
        Entities::Entry getEntry(ValueObjects::EntryId entryId) const;
        std::set<Entities::Entry> find(ValueObjects::EntryName entryName) const;
        void store(const Entities::Entry &entry) const;
        void remove(const Entities::Entry &entry) const;
        void modifyEntryName(const Entities::Entry &entry, const ValueObjects::EntryName &newEntryName) const;
        void modifyLogin(const Entities::Entry &entry, const ValueObjects::Login &newLogin) const;
        void modifyEncryptedPassword(const Entities::Entry &entry, const ValueObjects::EncryptedPassword &newEncryptedPassword) const;
        ValueObjects::EntryId nextId() const;
        EntryRepository(EntryRepository &other) = delete;
        void operator=(const EntryRepository&) = delete;
    private:
        explicit EntryRepository(const DatabaseInterface::DbInterface &dbInterface) : dbInterface(dbInterface) {}
        ~EntryRepository() { delete instance; }
        static EntryRepository* instance;
        DatabaseInterface::DbInterface dbInterface;
    };
} // DDD::Repositories

#endif //SRC_ENTRYREPOSITORY_H
