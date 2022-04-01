#include "adapters/database/DatabaseInterface.h"
#include "plugins/database/SQLiteDatabase.h"
#include "application/Cipher.h"
#include "plugins/encryption/BLOCK.h"
#include "plugins/encryption/CBC_Cipher.h"
#include "application/EntryRepository.h"
#include "application/PasswordEncryption.h"
#include "application/InstanceManager.h"
#include "adapters/ui/UiDataHelper.h"
#include "plugins/ui/CommandLineInterface.h"

int main() {
    const Plugins::Database::SQLiteDatabase database("../passwords.db");
    const Adapters::Database::DatabaseInterface dbInterface(&database);
    const DDD::Repositories::EntryRepository entryRepository(&dbInterface);
    InstanceManager::addEntryRepositoryPointer(&entryRepository);

    Adapters::UI::UiDataHelper uiDataHelper;
    Plugins::UI::CommandLineInterface cli(uiDataHelper);

    const ValueObjects::PlaintextPassword masterPassword = cli.requestMasterPassword();
//    if (!masterPasswordVerifier.verifyMasterPassword(masterPassword)) {}

    const Cipher* c = new CBC_Cipher(BLOCK::Serpent);
    const DDD::Services::PasswordEncryptor passwordEncryptor(c, masterPassword);
    const DDD::Services::PasswordDecryptor passwordDecryptor(c, masterPassword);
    InstanceManager::addEncryptionPointers(&passwordEncryptor, &passwordDecryptor);

    cli.mainloop();

    return 0;
}
