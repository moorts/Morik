#include "CommandLineInterface.h"
#include <iostream>

using namespace Plugins::UI;
using namespace DDD;

void CommandLineInterface::mainloop() const
{
    while (true) { return; }
}

ValueObjects::PlaintextPassword CommandLineInterface::requestMasterPassword() const
{
    std::cout << "Enter master password: ";
    std::string masterPasswordString;
    std::cin >> masterPasswordString;
    return ValueObjects::PlaintextPassword(masterPasswordString);
}
