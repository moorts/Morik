#include "InstanceManager.h"

const DDD::Repositories::EntryRepository* InstanceManager::entryRepository = nullptr;
const DDD::Services::PasswordEncryptor* InstanceManager::passwordEncryptor = nullptr;
const DDD::Services::PasswordDecryptor* InstanceManager::passwordDecryptor = nullptr;
