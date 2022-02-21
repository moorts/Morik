#ifndef SRC_ENTRY_H
#define SRC_ENTRY_H

#include "EntryId.h"
#include "EntryName.h"
#include "Username.h"
#include "EncryptedPassword.h"

namespace DDD::Entities {
    class Entry {
    public:
        Entry(const ValueObjects::EntryId &id, const ValueObjects::EntryName &name, const ValueObjects::Username &username, const ValueObjects::EncryptedPassword &password)
            : id(id), name(name), username(username), password(password) {}
        ValueObjects::EntryName name;
        ValueObjects::Username username;
        ValueObjects::EncryptedPassword password;
        const ValueObjects::EntryId getId() { return id; }
        bool operator==(const Entry &other) const { return other.id == id; }
    private:
        const ValueObjects::EntryId id;
    };
} // DDD::Entities

#endif //SRC_ENTRY_H
