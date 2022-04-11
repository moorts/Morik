#ifndef SRC_COMMANDLINEINTERFACE_H
#define SRC_COMMANDLINEINTERFACE_H

#include "../../adapters/ui/UiDataHelper.h"
#include "../../application/AbstractUserInterface.h"

namespace Plugins::UI {
    class CommandLineInterface : public AbstractUserInterface {
    public:
        CommandLineInterface(Adapters::UI::UiDataHelper uiDataHelper): uiDataHelper(uiDataHelper) {}
        void mainloop() const;
        DDD::ValueObjects::PlaintextPassword requestMasterPassword() const;
        DDD::ValueObjects::PlaintextPassword setNewMasterPassword() const;
        void wrongMasterPassword() const;
    private:
        Adapters::UI::UiDataHelper uiDataHelper;
    };
} // Plugins::UI

#endif //SRC_COMMANDLINEINTERFACE_H
