#ifndef SRC_ABSTRACTUSERINTERFACE_H
#define SRC_ABSTRACTUSERINTERFACE_H

#include "PlaintextPassword.h"

class AbstractUserInterface {
public:
    virtual void mainloop() const = 0;
    virtual DDD::ValueObjects::PlaintextPassword requestMasterPassword() const = 0;
    virtual DDD::ValueObjects::PlaintextPassword setNewMasterPassword() const = 0;
    virtual void wrongMasterPassword() const = 0;
};

#endif //SRC_ABSTRACTUSERINTERFACE_H
