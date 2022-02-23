#ifndef SRC_ENTRY_H
#define SRC_ENTRY_H

#include "EntryId.h"
#include "EntryName.h"
#include "Login.h"
#include "EncryptedPassword.h"

namespace DDD::Entities {
    class Entry {
    public:
        Entry(const ValueObjects::EntryId &entryId, const ValueObjects::EntryName &entryName, const ValueObjects::Login &login, const ValueObjects::EncryptedPassword &encryptedPassword)
            : entryId(entryId), entryName(entryName), login(login), encryptedPassword(encryptedPassword) {}
        ValueObjects::EntryName entryName;
        ValueObjects::Login login;
        ValueObjects::EncryptedPassword encryptedPassword;
        const ValueObjects::EntryId getEntryId() const { return entryId; }
        bool operator==(const Entry &other) const { return other.entryId == entryId; }
        bool operator<(const Entry &other) const { return other.entryId < entryId; }
    private:
        const ValueObjects::EntryId entryId;
    };
} // DDD::Entities

#endif //SRC_ENTRY_H
