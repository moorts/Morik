#ifndef SRC_DATABASECOLUMN_H
#define SRC_DATABASECOLUMN_H


namespace DatabaseInterface {
    enum DatabaseColumn {
        EntryId,
        EntryName,
        Login,
        EncryptedPassword
    };
    static const char * DatabaseColumnStrings[] = { "EntryId", "EntryName", "Login", "EncryptedPassword" };
    static const char * getDatabaseColumnString( int column )
    {
        return DatabaseColumnStrings[column];
    }
} // DatabaseInterface

#endif //SRC_DATABASECOLUMN_H
