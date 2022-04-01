#include "EntryFactory.h"
#include "PlaintextPassword.h"
#include "InstanceManager.h"

using namespace DDD;

Entities::Entry Factories::EntryFactory::createEntry(unsigned int id, std::string entryNameString, std::string loginString, std::string encryptedPasswordString)
{
    ValueObjects::EntryId entryId(id);
    ValueObjects::EntryName entryName(entryNameString);
    ValueObjects::Login login(loginString);
    ValueObjects::EncryptedPassword encryptedPassword(encryptedPasswordString);
    return Entities::Entry(entryId, entryName, login, encryptedPassword);
}

Entities::Entry Factories::EntryFactory::createEntryFromPlaintext(ValueObjects::EntryId entryId, std::string entryNameString, std::string loginString, std::string plaintextPasswordString)
{
    ValueObjects::EntryName entryName(entryNameString);
    ValueObjects::Login login(loginString);
    ValueObjects::PlaintextPassword plaintextPassword(plaintextPasswordString);
    ValueObjects::EncryptedPassword encryptedPassword = InstanceManager::passwordEncryptor->encrypt(plaintextPassword);
    return Entities::Entry(entryId, entryName, login, encryptedPassword);
}
