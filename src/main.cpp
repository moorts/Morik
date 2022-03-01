#include "adapters/database/DbInterface.h"
#include "plugins/database/SQLiteDatabase.h"
#include "application/Cipher.h"
#include "plugins/encryption/BLOCK.h"
#include "plugins/encryption/CBC_Cipher.h"
#include "application/DDD/EntryRepository.h"
#include "application/DDD/PasswordEncryption.h"
#include "application/InstanceManager.h"

int main() {
    const Plugins::Database::SQLiteDatabase database("../passwords.db");
    const Adapters::Database::DbInterface dbInterface(&database);
    const DDD::Repositories::EntryRepository entryRepository(&dbInterface);

    const ValueObjects::PlaintextPassword masterPassword("100%safePassword");

    const Cipher* c = new CBC_Cipher(BLOCK::Serpent);
    const DDD::Services::PasswordEncryptor passwordEncryptor(c, masterPassword);
    const DDD::Services::PasswordDecryptor passwordDecryptor(c, masterPassword);

    InstanceManager::addPointers(&entryRepository, &passwordEncryptor, &passwordDecryptor);

    return 0;
}
