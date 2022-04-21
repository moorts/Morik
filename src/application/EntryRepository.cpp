#include "EntryRepository.h"

using namespace DDD;
using namespace DDD::Repositories;

Entities::Entry EntryRepository::getEntry(ValueObjects::EntryId entryId) const
{
    return dbInterface->getEntry(entryId);
}

std::set<Entities::Entry> EntryRepository::find(ValueObjects::EntryName entryName) const
{
    return dbInterface->getEntries(entryName);
}

std::set<Entities::Entry> EntryRepository::getAllEntries() const
{
    return dbInterface->getAllEntries();
}

void EntryRepository::store(const Entities::Entry &entry) const
{
    dbInterface->insertEntry(entry);
}

void EntryRepository::remove(const Entities::Entry &entry) const
{
    dbInterface->removeEntry(entry.getEntryId());
}

void EntryRepository::modifyEntryName(const Entities::Entry &entry, const ValueObjects::EntryName &newEntryName) const
{
    dbInterface->modifyEntry(entry.getEntryId(), DatabaseColumn::EntryName, newEntryName.getString());
}

void EntryRepository::modifyLogin(const Entities::Entry &entry, const ValueObjects::Login &newLogin) const
{
    dbInterface->modifyEntry(entry.getEntryId(), DatabaseColumn::Login, newLogin.getString());
}

void EntryRepository::modifyEncryptedPassword(const Entities::Entry &entry, const ValueObjects::EncryptedPassword &newEncryptedPassword) const
{
    dbInterface->modifyEntry(entry.getEntryId(), DatabaseColumn::EncryptedPassword, newEncryptedPassword.getString());
}

ValueObjects::EntryId EntryRepository::nextId() const
{
    std::set<Entities::Entry> allEntries = dbInterface->getAllEntries();
    return ValueObjects::EntryId(allEntries.rbegin()->getEntryId().getInt()+1);
}
