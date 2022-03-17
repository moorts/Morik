#ifndef SRC_ABSTRACTDATABASEINTERFACEMOCK_H
#define SRC_ABSTRACTDATABASEINTERFACEMOCK_H

#include "../../application/AbstractDatabaseInterface.h"
#include "../../cmake-build-debug/_deps/googletest-src/googlemock/include/gmock/gmock.h"

class AbstractDatabaseInterfaceMock : public AbstractDatabaseInterface {
public:
    MOCK_METHOD(DDD::Entities::Entry, getEntry, (const DDD::ValueObjects::EntryId &entryId), (const, override));
    MOCK_METHOD(std::set<DDD::Entities::Entry>, getEntries, (const DDD::ValueObjects::EntryName &entryName), (const, override));
    MOCK_METHOD(std::set<DDD::Entities::Entry>, getAllEntries, (), (const, override));
    MOCK_METHOD(bool, insertEntry, (const DDD::Entities::Entry &entry), (const, override));
    MOCK_METHOD(bool, removeEntry, (const DDD::ValueObjects::EntryId &entryId), (const, override));
    MOCK_METHOD(bool, modifyEntry, (const DDD::ValueObjects::EntryId &entryId, const DatabaseColumn &column, const std::string &newValue), (const, override));
};


#endif //SRC_ABSTRACTDATABASEINTERFACEMOCK_H
