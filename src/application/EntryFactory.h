#ifndef SRC_ENTRYFACTORY_H
#define SRC_ENTRYFACTORY_H

#include <string>
#include "Entry.h"

namespace DDD::Factories
{
    class EntryFactory
    {
    public:
        static Entities::Entry createEntry(unsigned int id, std::string entryNameString, std::string loginString, std::string encryptedPasswordString);
        static Entities::Entry createEntryFromPlaintext(ValueObjects::EntryId id, std::string entryNameString, std::string loginString, std::string plaintextPasswordString);
    private:
    };
} // DDD::Factories

#endif //SRC_ENTRYFACTORY_H
