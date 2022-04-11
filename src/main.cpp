#include "adapters/database/DatabaseInterface.h"
#include "plugins/database/SQLiteDatabase.h"
#include "application/Cipher.h"
#include "plugins/encryption/BLOCK.h"
#include "plugins/encryption/CBC_Cipher.h"
#include "plugins/encryption/DefaultHash.h"
#include "application/EntryRepository.h"
#include "application/PasswordEncryption.h"
#include "application/PasswordVerifier.h"
#include "application/InstanceManager.h"
#include "adapters/ui/UiDataHelper.h"
#include "plugins/ui/CommandLineInterface.h"

int main() {
    const Plugins::Database::SQLiteDatabase database("../passwords.db");
    const Adapters::Database::DatabaseInterface dbInterface(&database);
    const DDD::Repositories::EntryRepository entryRepository(&dbInterface);
    InstanceManager::addEntryRepositoryPointer(&entryRepository);

    const Hash* hash = new DefaultHash();
    const DDD::Services::MasterPasswordVerifier masterPasswordVerifier(hash);

    Adapters::UI::UiDataHelper uiDataHelper;
    Plugins::UI::CommandLineInterface cli(uiDataHelper);

    std::string masterPasswordString;
    if (!masterPasswordVerifier.isMasterPasswordSet()) {
        masterPasswordString = cli.setNewMasterPassword().getString();
        masterPasswordVerifier.setMasterPassword(masterPasswordString);
    } else {
        masterPasswordString = cli.requestMasterPassword().getString();
        if (!masterPasswordVerifier.verifyMasterPassword(masterPasswordString)) {
            cli.wrongMasterPassword();
            exit(1);
        }
    }
    const ValueObjects::PlaintextPassword masterPassword(masterPasswordString);

    const Cipher* c = new CBC_Cipher(BLOCK::Serpent);
    const DDD::Services::PasswordEncryptor passwordEncryptor(c, masterPassword);
    const DDD::Services::PasswordDecryptor passwordDecryptor(c, masterPassword);
    InstanceManager::addEncryptionPointers(&passwordEncryptor, &passwordDecryptor);

    cli.mainloop();

    return 0;
}
