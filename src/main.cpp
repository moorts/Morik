#include "application/DbInterface.h"
#include "plugins/database/SQLiteDatabase.h"
#include "encryption/Cipher.h"
#include "encryption/PasswordEncryptionHandler.h"
#include "encryption/CipherBase.h"
#include "encryption/AES.h"

int main() {
    const Plugins::Database::SQLiteDatabase database("passwords.db");
    DatabaseInterface::DbInterface dbInterface(&database);
    return 0;
}
