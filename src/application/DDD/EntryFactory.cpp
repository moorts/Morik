#include "EntryFactory.h"
#include "PlaintextPassword.h"
#include "../InstanceManager.h"

using namespace DDD::Factories;
using namespace DDD::Entities;

Entry EntryFactory::createEntry(unsigned int id, std::string entryNameString, std::string loginString, std::string encryptedPasswordString)
{
    DDD::ValueObjects::EntryId entryId(id);
    DDD::ValueObjects::EntryName entryName(entryNameString);
    DDD::ValueObjects::Login login(loginString);
    DDD::ValueObjects::EncryptedPassword encryptedPassword(encryptedPasswordString);
    return Entry(entryId, entryName, login, encryptedPassword);
}

Entry EntryFactory::createEntryFromPlaintext(unsigned int id, std::string entryNameString, std::string loginString, std::string plaintextPasswordString)
{
    DDD::ValueObjects::EntryId entryId(id);
    DDD::ValueObjects::EntryName entryName(entryNameString);
    DDD::ValueObjects::Login login(loginString);
    DDD::ValueObjects::PlaintextPassword plaintextPassword(plaintextPasswordString);
    DDD::ValueObjects::EncryptedPassword encryptedPassword = InstanceManager::getInstance()->passwordEncryptor.encrypt(plaintextPassword);
    return Entry(entryId, entryName, login, encryptedPassword);
}
