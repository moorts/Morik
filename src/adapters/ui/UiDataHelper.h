#include <set>
#include <string>
#include "../../application/EntryName.h"
#include "../../application/Entry.h"

#ifndef SRC_UIDATAHELPER_H
#define SRC_UIDATAHELPER_H

namespace Adapters::UI {
    class UiDataHelper {
    public:
        std::multiset<DDD::ValueObjects::EntryName> getAllEntryNames() const;
        void createNewEntry(const std::string& entryNameString, const std::string& loginString, const std::string& plaintextPasswordString) const;
        void modifyPassword(const DDD::Entities::Entry& entry, const std::string& newPlaintextPasswordString) const;
    };
} // Adapters::UI

#endif //SRC_UIDATAHELPER_H
