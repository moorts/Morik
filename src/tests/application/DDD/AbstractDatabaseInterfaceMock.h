#ifndef SRC_ABSTRACTDATABASEINTERFACEMOCK_H
#define SRC_ABSTRACTDATABASEINTERFACEMOCK_H

#include "../../../application/AbstractDatabaseInterface.h"

class AbstractDatabaseInterfaceMock : public AbstractDatabaseInterface {
public:
    DDD::Entities::Entry getEntry(const DDD::ValueObjects::EntryId &entryId) const
    {
        if (entryId == ValueObjects::EntryId(1))
            return Entities::Entry(entryId, ValueObjects::EntryName("TestEntry"), ValueObjects::Login("TestLogin"), ValueObjects::EncryptedPassword("SomeEncryptedPassword"));
        throw std::domain_error("no Entry with provided ID");
    }

    std::set<DDD::Entities::Entry> getEntries(const DDD::ValueObjects::EntryName &entryName) const
    {
        std::set<Entities::Entry> entries;
        if (entryName == ValueObjects::EntryName("TestEntry")) {
            entries.emplace(ValueObjects::EntryId(1), entryName, ValueObjects::Login("TestLogin"), ValueObjects::EncryptedPassword("SomeEncryptedPassword"));
            entries.emplace(ValueObjects::EntryId(2), entryName, ValueObjects::Login("AnotherTestLogin"), ValueObjects::EncryptedPassword("AnotherEncryptedPassword"));
        }
        return entries;
    }
    std::set<DDD::Entities::Entry> getAllEntries() const { return std::set<Entities::Entry>(); }
    bool insertEntry(const DDD::Entities::Entry &entry) const { return false; }
    bool removeEntry(const DDD::ValueObjects::EntryId &entryId) const { return false; }
    bool modifyEntry(const DDD::ValueObjects::EntryId &entryId, const DatabaseColumn &column, const std::string &newValue) const { return false; }
};


#endif //SRC_ABSTRACTDATABASEINTERFACEMOCK_H
