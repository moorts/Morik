#include "UiDataHelper.h"
#include "../../application/InstanceManager.h"
#include "../../application/EntryFactory.h"

using namespace Adapters::UI;
using namespace DDD;

std::multiset<DDD::ValueObjects::EntryName> UiDataHelper::getAllEntryNames() const
{
    std::set<Entities::Entry> allEntries = InstanceManager::entryRepository->getAllEntries();
    std::multiset<ValueObjects::EntryName> allEntryNames;
    for (const Entities::Entry& entry : allEntries) {
        allEntryNames.emplace(entry.entryName);
    }
    return allEntryNames;
}

void UiDataHelper::createNewEntry(const std::string& entryNameString, const std::string& loginString, const std::string& plaintextPasswordString) const
{
    ValueObjects::EntryId newId = InstanceManager::entryRepository->nextId();
    Entities::Entry newEntry = DDD::Factories::EntryFactory::createEntryFromPlaintext(newId, entryNameString, loginString, plaintextPasswordString);
    InstanceManager::entryRepository->store(newEntry);
}

void UiDataHelper::modifyPassword(const DDD::Entities::Entry& entry, const std::string& newPlaintextPasswordString) const
{
    ValueObjects::EncryptedPassword newEncryptedPassword = InstanceManager::passwordEncryptor->encrypt(ValueObjects::PlaintextPassword(newPlaintextPasswordString));
    InstanceManager::entryRepository->modifyEntry(entry, newEncryptedPassword);
}
