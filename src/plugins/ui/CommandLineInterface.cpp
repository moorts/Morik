#include "CommandLineInterface.h"
#include <iostream>
#include "../../application/InstanceManager.h"

using namespace Plugins::UI;
using namespace DDD;

void CommandLineInterface::mainloop() const
{
    while (true)
    {
        std::cout << "What do you want to do?" << std::endl;
        std::cout << "1 - list all entry names" << std::endl;
        std::cout << "2 - select existing entry" << std::endl;
        std::cout << "3 - add new entry" << std::endl;
        std::cout << "4 - exit" << std::endl;

        std::string selectionString;
        std::cin >> selectionString;
        int selection;
        try {
            selection = std::stoi(selectionString);
        } catch (const std::invalid_argument& exception) {
            std::cout << "Invalid selection" << std::endl << std::endl;
            continue;
        }
        switch(selection)
        {
            case 1: {
                std::multiset<ValueObjects::EntryName> entryNames = uiDataHelper.getAllEntryNames();
                for (const ValueObjects::EntryName &entryName: entryNames) {
                    std::cout << entryName.getString() << std::endl;
                }
                break;
            }
            case 2: {
                std::cout << "How do you want to select a specific entry?" << std::endl;
                std::cout << "1 - list all entries" << std::endl;
                std::cout << "2 - search for entries" << std::endl;

                std::map<int, Entities::Entry> entrySelectionMap;
                int entryIndex = 1;
                std::string innerSelectionString;
                std::cin >> innerSelectionString;
                int innerSelection;
                try {
                    innerSelection = std::stoi(innerSelectionString);
                } catch (const std::invalid_argument &exception) {
                    std::cout << "Invalid selection" << std::endl << std::endl;
                    continue;
                }

                if (innerSelection == 1) {
                    std::set<Entities::Entry> allEntries = InstanceManager::entryRepository->getAllEntries();
                    for (const Entities::Entry &entry: allEntries) {
                        std::cout << entryIndex << " - " << entry.entryName.getString() << " : "
                                  << entry.login.getString() << std::endl;
                        entrySelectionMap.emplace(entryIndex++, entry);
                    }
                } else if (innerSelection == 2) {
                    std::string searchString;
                    std::cout << "Enter entry name" << std::endl;
                    std::cin >> searchString;
                    std::set<Entities::Entry> foundEntries = InstanceManager::entryRepository->find(searchString);
                    for (const Entities::Entry &entry: foundEntries) {
                        std::cout << entryIndex << " - " << entry.entryName.getString() << " : "
                                  << entry.login.getString() << std::endl;
                        entrySelectionMap.emplace(entryIndex++, entry);
                    }
                } else {
                    std::cout << "Invalid selection" << std::endl;
                    continue;
                }
                std::cout << "selection: ";

                int entrySelection;
                std::string entrySelectionString;
                std::cin >> entrySelectionString;
                try {
                    entrySelection = std::stoi(entrySelectionString);
                } catch (const std::invalid_argument &exception) {
                    std::cout << "Invalid selection" << std::endl << std::endl;
                    continue;
                }

                if (entrySelection > entryIndex + 1 || entrySelection < 1) {
                    std::cout << "Invalid selection" << std::endl;
                } else {
                    Entities::Entry selectedEntry = entrySelectionMap.at(entrySelection);
                    std::cout << "What do you want to do with the selected entry?" << std::endl;
                    std::cout << "1 - get password" << std::endl;
                    std::cout << "2 - modify entry" << std::endl;
                    std::cout << "3 - remove entry" << std::endl;

                    int actionSelection = 0;
                    std::cin >> actionSelection;

                    if (actionSelection == 1) {
                        std::cout << InstanceManager::passwordDecryptor->decrypt(
                                selectedEntry.encryptedPassword).getString() << std::endl;
                    } else if (actionSelection == 2) {
                        std::cout << "Which field do you want to modify?" << std::endl;
                        std::cout << "1 - entry name" << std::endl;
                        std::cout << "2 - login" << std::endl;
                        std::cout << "3 - password" << std::endl;
                        int fieldSelection;
                        std::string fieldSelectionString;
                        std::cin >> fieldSelectionString;
                        try {
                            fieldSelection = std::stoi(fieldSelectionString);
                        } catch (const std::invalid_argument &exception) {
                            std::cout << "Invalid selection" << std::endl << std::endl;
                            continue;
                        }

                        if (fieldSelection == 1) {
                            std::cout << "Enter new entry name: ";
                            std::string newEntryNameString;
                            std::cin >> newEntryNameString;
                            InstanceManager::entryRepository->modifyEntry(selectedEntry,
                                                                          ValueObjects::EntryName(newEntryNameString));
                        } else if (fieldSelection == 2) {
                            std::cout << "Enter new login: ";
                            std::string newLoginString;
                            std::cin >> newLoginString;
                            InstanceManager::entryRepository->modifyEntry(selectedEntry,
                                                                          ValueObjects::Login(newLoginString));
                        } else if (fieldSelection == 3) {
                            std::cout << "Enter new password: ";
                            std::string newPasswordString;
                            std::cin >> newPasswordString;
                            uiDataHelper.modifyPassword(selectedEntry, newPasswordString);
                        } else {
                            std::cout << "Invalid selection" << std::endl;
                        }
                    } else if (actionSelection == 3) {
                        InstanceManager::entryRepository->remove(selectedEntry);
                    } else {
                        std::cout << "Invalid selection" << std::endl;
                    }
                }
                break;
            }
            case 3: {
                std::string entryNameString;
                std::string loginString;
                std::string passwordString;
                std::cout << "Enter entry name: ";
                std::cin >> entryNameString;
                std::cout << "Enter login: ";
                std::cin >> loginString;
                std::cout << "Do you want to enter a password or generate it?" << std::endl;
                std::cout << "1 - enter password by hand" << std::endl;
                std::cout << "2 - generate password" << std::endl;
                int selection;
                std::string selectionString;
                std::cin >> selectionString;
                try {
                    selection = std::stoi(selectionString);
                } catch (const std::invalid_argument &exception) {
                    std::cout << "Invalid selection" << std::endl << std::endl;
                    continue;
                }
                if (selection == 1) {
                    std::cout << "Enter password: ";
                    std::cin >> passwordString;
                } else if (selection == 2) {
                    std::cout << "Enter the length the generated password should have: ";
                    int length;
                    std::string lengthString;
                    std::cin >> lengthString;
                    try {
                        length = std::stoi(lengthString);
                    } catch (const std::invalid_argument &exception) {
                        std::cout << "Invalid length" << std::endl << std::endl;
                        continue;
                    }
                    passwordString = InstanceManager::passwordGenerator->getRandomPassword(ValueObjects::PasswordLength(length)).getString();
                } else {
                    std::cout << "Invalid selection" << std::endl << std::endl;
                    continue;
                }
                uiDataHelper.createNewEntry(entryNameString, loginString, passwordString);
                break;
            }
            case 4: {
                return;
            }
            default: {
                std::cout << "invalid selection" << std::endl;
            }
        }
        std::cout << std::endl;
    }
}

ValueObjects::PlaintextPassword CommandLineInterface::requestMasterPassword() const
{
    std::cout << "Enter master password: ";
    std::string masterPasswordString;
    std::cin >> masterPasswordString;
    return ValueObjects::PlaintextPassword(masterPasswordString);
}

ValueObjects::PlaintextPassword CommandLineInterface::setNewMasterPassword() const
{
    std::cout << "Set new master password: ";
    std::string masterPasswordString;
    std::cin >> masterPasswordString;
    return ValueObjects::PlaintextPassword(masterPasswordString);
}

void CommandLineInterface::wrongMasterPassword() const
{
    std::cout << "Wrong master password has been entered" << std::endl;
}
