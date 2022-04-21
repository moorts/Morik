#include "adapters/database/DatabaseInterface.h"
#include "plugins/database/SQLiteDatabase.h"
#include "application/Cipher.h"
#include "plugins/encryption/BLOCK.h"
#include "plugins/encryption/CBC_Cipher.h"
#include "plugins/encryption/DefaultHash.h"
#include "application/EntryRepository.h"
#include "application/PasswordEncryption.h"
#include "application/MasterPasswordVerifier.h"
#include "application/InstanceManager.h"
#include "adapters/ui/UiDataHelper.h"
#include "plugins/ui/CommandLineInterface.h"
#include "plugins/prng/MersenneTwister.h"
#include "application/PasswordGenerator.h"

int main() {
    const Plugins::Database::SQLiteDatabase database("../passwords.db");
    const Adapters::Database::DatabaseInterface dbInterface(&database);
    const DDD::Repositories::EntryRepository entryRepository(&dbInterface);
    InstanceManager::addEntryRepositoryPointer(&entryRepository);

    Adapters::UI::UiDataHelper uiDataHelper;
    Plugins::UI::CommandLineInterface cli(uiDataHelper);

    const Hash* hash = new DefaultHash();
    const DDD::Services::MasterPasswordVerifier masterPasswordVerifier(hash, &cli);

    std::string masterPasswordString;
    try {
        masterPasswordString = masterPasswordVerifier.getVerifiedMasterPassword().getString();
    } catch (const std::domain_error& exception) {
        exit(1);
    }
    const ValueObjects::PlaintextPassword masterPassword(masterPasswordString);

    const Cipher* c = new CBC_Cipher(BLOCK::Serpent);
    const DDD::Services::PasswordEncryptor passwordEncryptor(c, masterPassword);
    const DDD::Services::PasswordDecryptor passwordDecryptor(c, masterPassword);
    InstanceManager::addEncryptionPointers(&passwordEncryptor, &passwordDecryptor);

    std::random_device device;
    MersenneTwister mt(device());
    DDD::Services::PasswordGenerator passwordGenerator(&mt);
    InstanceManager::addPasswordGeneratorPointer(&passwordGenerator);

    cli.mainloop();

    return 0;
}
