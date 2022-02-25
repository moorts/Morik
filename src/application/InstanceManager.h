#ifndef SRC_INSTANCEMANAGER_H
#define SRC_INSTANCEMANAGER_H

#include "DDD/EntryRepository.h"
#include "DDD/PasswordEncryption.h"

class InstanceManager final {
public:
    static void createInstance(const DDD::Repositories::EntryRepository &entryRepository, const DDD::Services::PasswordEncryptor &passwordEncryptor, const DDD::Services::PasswordDecryptor &passwordDecryptor);
    static InstanceManager* getInstance();
    InstanceManager(InstanceManager &other) = delete;
    void operator=(const InstanceManager&) = delete;
    const DDD::Repositories::EntryRepository entryRepository;
    const DDD::Services::PasswordEncryptor passwordEncryptor;
    const DDD::Services::PasswordDecryptor passwordDecryptor;
private:
    explicit InstanceManager(const DDD::Repositories::EntryRepository &entryRepository, const DDD::Services::PasswordEncryptor &passwordEncryptor, const DDD::Services::PasswordDecryptor &passwordDecryptor) : entryRepository(entryRepository), passwordEncryptor(passwordEncryptor), passwordDecryptor(passwordDecryptor) {}
    ~InstanceManager() { delete instance; }
    static InstanceManager* instance;
};


#endif //SRC_INSTANCEMANAGER_H
