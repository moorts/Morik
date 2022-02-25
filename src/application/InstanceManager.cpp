#include "InstanceManager.h"

InstanceManager* InstanceManager::instance = nullptr;

void InstanceManager::createInstance(const DDD::Repositories::EntryRepository &entryRepository, const DDD::Services::PasswordEncryptor &passwordEncryptor, const DDD::Services::PasswordDecryptor &passwordDecryptor)
{
    if (!instance)
        instance = new InstanceManager(entryRepository, passwordEncryptor, passwordDecryptor);
}

InstanceManager* InstanceManager::getInstance()
{
    return instance;
}
