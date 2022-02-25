#include "EntryFactory.h"
#include "PlaintextPassword.h"
#include "../InstanceManager.h"

using namespace DDD::Factories;
using namespace DDD::Entities;
using namespace DDD::ValueObjects;

Entry EntryFactory::createEntry(unsigned int id, std::string entryNameString, std::string loginString, std::string encryptedPasswordString)
{
    EntryId entryId(id);
    EntryName entryName(entryNameString);
    Login login(loginString);
    EncryptedPassword encryptedPassword(encryptedPasswordString);
    return Entry(entryId, entryName, login, encryptedPassword);
}

Entry EntryFactory::createEntryFromPlaintext(unsigned int id, std::string entryNameString, std::string loginString, std::string plaintextPasswordString)
{
    EntryId entryId(id);
    EntryName entryName(entryNameString);
    Login login(loginString);
    PlaintextPassword plaintextPassword(plaintextPasswordString);
    EncryptedPassword encryptedPassword = InstanceManager::getInstance()->passwordEncryptor.encrypt(plaintextPassword);
    return Entry(entryId, entryName, login, encryptedPassword);
}
