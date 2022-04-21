#ifndef SRC_MASTERPASSWORTVERIFIER_H
#define SRC_MASTERPASSWORDVERIFIER_H

#include "EntryFactory.h"
#include "InstanceManager.h"
#include "DatabaseColumn.h"
#include "Hash.h"
#include "AbstractUserInterface.h"
#include <stdexcept>

using namespace DDD;

namespace DDD::Services {
    class MasterPasswordVerifier {
    public:
        MasterPasswordVerifier(const Hash* hash, const AbstractUserInterface* ui) : hash(hash), ui(ui) {}
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
                InstanceManager::entryRepository->modifyEncryptedPassword(entry, verificationHash);
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

        ValueObjects::PlaintextPassword getVerifiedMasterPassword() const {
            std::string masterPasswordString;
            if (!isMasterPasswordSet()) {
                masterPasswordString = ui->setNewMasterPassword().getString();
                setMasterPassword(masterPasswordString);
            } else {
                masterPasswordString = ui->requestMasterPassword().getString();
                if (!verifyMasterPassword(masterPasswordString)) {
                    ui->wrongMasterPassword();
                    throw std::domain_error("wrong master password");
                }
            }
            return ValueObjects::PlaintextPassword(masterPasswordString);
        }

    private:
        const Hash* hash;
        const AbstractUserInterface* ui;
    };
}

#endif
