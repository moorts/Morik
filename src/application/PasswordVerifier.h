#ifndef SRC_PASSWORTVERIFIER_H
#define SRC_PASSWORDVERIFIER_H

#include "InstanceManager.h"
#include "DatabaseColumn.h"
#include "Hash.h"

using namespace DDD;

namespace DDD::Services {
    class MasterPasswordVerifier {
    public:
        MasterPasswordVerifier(const Hash* hash) : hash(hash) {}
        bool verifyMasterPassword(ValueObjects::PlaintextPassword masterPassword) const {
            ValueObjects::EncryptedPassword storedMasterPasswordHash = InstanceManager::entryRepository->getEntry(ValueObjects::EntryId(0)).encryptedPassword;

            std::string inputMasterPasswordHash = this->hash->compute(this->hash->compute(masterPassword.getString()));

            return inputMasterPasswordHash == storedMasterPasswordHash.getString();
        }

        void setMasterPassword(ValueObjects::PlaintextPassword masterPassword) const {
            const ValueObjects::EncryptedPassword newHash(this->hash->compute(this->hash->compute(masterPassword.getString())));

            try {
                Entities::Entry entry = InstanceManager::entryRepository->getEntry(ValueObjects::EntryId(0));
                InstanceManager::entryRepository->modifyEntry(entry, newHash);
            } catch (...) {
                Entities::Entry newMasterPasswordHash(ValueObjects::EntryId(0), ValueObjects::EntryName("masterPasswordHash"), ValueObjects::Login("master"), newHash);
                InstanceManager::entryRepository->store(newMasterPasswordHash);
            }
        }

    private:
        const Hash* hash;
    };
}

#endif
