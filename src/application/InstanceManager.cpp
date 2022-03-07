#include "InstanceManager.h"

const Repositories::EntryRepository* InstanceManager::entryRepository = nullptr;
const Services::PasswordEncryptor* InstanceManager::passwordEncryptor = nullptr;
const Services::PasswordDecryptor* InstanceManager::passwordDecryptor = nullptr;
