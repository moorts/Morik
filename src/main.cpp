#include "application/DbInterface.h"
#include "plugins/database/SQLiteDatabase.h"
#include "application/Cipher.h"
#include "plugins/encryption/BLOCK.h"
#include "plugins/encryption/CBC_Cipher.h"
#include "application/DDD/EntryRepository.h"

int main() {
    const Plugins::Database::SQLiteDatabase database("../passwords.db");
    DatabaseInterface::DbInterface dbInterface(&database);
    DDD::Repositories::EntryRepository::createInstance(dbInterface);

    const Cipher* c = new CBC_Cipher(BLOCK::Serpent);

    return 0;
}
