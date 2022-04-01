#ifndef SRC_INSTANCEMANAGER_H
#define SRC_INSTANCEMANAGER_H

#include "EntryRepository.h"
#include "PasswordEncryption.h"

using namespace DDD;

class InstanceManager {
public:
    static void addEntryRepositoryPointer(const Repositories::EntryRepository* pEntryRepository) { entryRepository = pEntryRepository; }
    static void addEncryptionPointers(const Services::PasswordEncryptor* pPasswordEncryptor, const Services::PasswordDecryptor* pPasswordDecryptor)
    {
        passwordEncryptor = pPasswordEncryptor;
        passwordDecryptor = pPasswordDecryptor;
    }
    static const Repositories::EntryRepository* entryRepository;
    static const Services::PasswordEncryptor* passwordEncryptor;
    static const Services::PasswordDecryptor* passwordDecryptor;
};


#endif //SRC_INSTANCEMANAGER_H
