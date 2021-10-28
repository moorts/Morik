#include "application/DbInterface.h"
#include "plugins/database/SQLiteDatabase.h"
#include "encryption/Cipher.h"
#include "encryption/PasswordEncryptionHandler.h"
#include "encryption/BLOCK.h"
#include "encryption/CBC_Cipher.h"
#include "encryption/EncryptionInterface.h"


int main() {
    const Plugins::Database::SQLiteDatabase database("passwords.db");
    DatabaseInterface::DbInterface dbInterface(&database);
    return 0;
}
