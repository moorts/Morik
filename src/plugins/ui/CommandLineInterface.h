#ifndef SRC_COMMANDLINEINTERFACE_H
#define SRC_COMMANDLINEINTERFACE_H

#include "../../adapters/ui/UiDataHelper.h"
#include "../../application/PlaintextPassword.h"

namespace Plugins::UI {
    class CommandLineInterface {
    public:
        CommandLineInterface(Adapters::UI::UiDataHelper uiDataHelper): uiDataHelper(uiDataHelper) {}
        int mainloop() const;
        DDD::ValueObjects::PlaintextPassword requestMasterPassword() const;
    private:
        Adapters::UI::UiDataHelper uiDataHelper;
    };
} // Plugins::UI

#endif //SRC_COMMANDLINEINTERFACE_H
