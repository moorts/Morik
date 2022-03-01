#ifndef SRC_INSTANCEMANAGER_H
#define SRC_INSTANCEMANAGER_H

#include "DDD/EntryRepository.h"
#include "DDD/PasswordEncryption.h"

class InstanceManager {
public:
    static void addPointers(const DDD::Repositories::EntryRepository* pEntryRepository, const DDD::Services::PasswordEncryptor* pPasswordEncryptor, const DDD::Services::PasswordDecryptor* pPasswordDecryptor)
    {
        entryRepository = pEntryRepository;
        passwordEncryptor = pPasswordEncryptor;
        passwordDecryptor = pPasswordDecryptor;
    }
    static const DDD::Repositories::EntryRepository* entryRepository;
    static const DDD::Services::PasswordEncryptor* passwordEncryptor;
    static const DDD::Services::PasswordDecryptor* passwordDecryptor;
};


#endif //SRC_INSTANCEMANAGER_H
