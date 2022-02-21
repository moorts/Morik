#ifndef SRC_ENTRY_H
#define SRC_ENTRY_H

#include "EntryId.h"
#include "EntryName.h"
#include "Username.h"
#include "EncryptedPassword.h"

namespace DDD::Entities {
    class Entry {
    public:
        Entry(const EntryId &id, const EntryName &name, const Username &username, const EncryptedPassword &password) : id(id), name(name), username(username), password(password) {}
        EntryName name;
        Username username;
        EncryptedPassword password;
        const EntryId getId() { return id; }
        bool operator==(const Entry &other) const { return other.id == id; }
    private:
        const EntryId id;
    };
} // DDD::Entities

#endif //SRC_ENTRY_H
