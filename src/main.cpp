#include "application/DbInterface.h"
#include "plugins/database/SQLiteDatabase.h"
#include "plugins/encryption/Cipher.h"
#include "plugins/encryption/BLOCK.h"
#include "plugins/encryption/CBC_Cipher.h"
#include "application/EncryptionInterface.h"


int main() {
    const Plugins::Database::SQLiteDatabase database("passwords.db");
    DatabaseInterface::DbInterface dbInterface(&database);

    const Cipher* c = new CBC_Cipher(BLOCK::Serpent);
    EncryptionInterface encInterface(c);
    return 0;
}
