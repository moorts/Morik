#include "CommandLineInterface.h"
#include <iostream>

using namespace Plugins::UI;
using namespace DDD;

int CommandLineInterface::mainloop() const
{
    bool exit = false;
    while (!exit) { exit = true; }
    return 0;
}

ValueObjects::PlaintextPassword CommandLineInterface::requestMasterPassword() const
{
    std::cout << "Enter master password: ";
    std::string masterPasswordString;
    std::cin >> masterPasswordString;
    return ValueObjects::PlaintextPassword(masterPasswordString);
}
