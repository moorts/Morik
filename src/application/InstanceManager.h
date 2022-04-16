#ifndef SRC_INSTANCEMANAGER_H
#define SRC_INSTANCEMANAGER_H

#include "EntryRepository.h"
#include "PasswordEncryption.h"
#include "PasswordGenerator.h"

using namespace DDD;

class InstanceManager {
public:
    static void addPointers(const Repositories::EntryRepository* pEntryRepository, const Services::PasswordEncryptor* pPasswordEncryptor, const Services::PasswordDecryptor* pPasswordDecryptor)
    {
        entryRepository = pEntryRepository;
        passwordEncryptor = pPasswordEncryptor;
        passwordDecryptor = pPasswordDecryptor;
    }
    static void addPasswordGeneratorPointer(Services::PasswordGenerator* const pPasswordGenerator) { passwordGenerator = pPasswordGenerator; }
    static const Repositories::EntryRepository* entryRepository;
    static const Services::PasswordEncryptor* passwordEncryptor;
    static const Services::PasswordDecryptor* passwordDecryptor;
    static Services::PasswordGenerator* passwordGenerator;
};


#endif //SRC_INSTANCEMANAGER_H
