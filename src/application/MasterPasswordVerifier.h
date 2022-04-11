#ifndef SRC_MASTERPASSWORTVERIFIER_H
#define SRC_MASTERPASSWORDVERIFIER_H

#include "EntryFactory.h"
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
            const std::string rawHash = this->hash->compute(this->hash->compute(masterPassword.getString()));
            const ValueObjects::EncryptedPassword verificationHash(rawHash);

            try {
                Entities::Entry entry = InstanceManager::entryRepository->getEntry(ValueObjects::EntryId(0));
                InstanceManager::entryRepository->modifyEntry(entry, verificationHash);
            } catch (...) {
                Entities::Entry newMasterPasswordHash = Factories::EntryFactory::createEntry(0, "masterPasswordHash", "master", rawHash);
                InstanceManager::entryRepository->store(newMasterPasswordHash);
            }
        }

        bool isMasterPasswordSet() const {
            try {
                InstanceManager::entryRepository->getEntry(ValueObjects::EntryId(0));
                return true;
            } catch (...) {
                return false;
            }
        }

    private:
        const Hash* hash;
    };
}

#endif
