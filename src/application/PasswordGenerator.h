#ifndef SRC_PASSWORDGENERATOR_H
#define SRC_PASSWORDGENERATOR_H

#include "PseudoRandomNumberGenerator.h"
#include "PlaintextPassword.h"
#include "PasswordLength.h"
#include <iostream>

namespace DDD::Services {
    class PasswordGenerator {
    public:
        PasswordGenerator(PseudoRandomNumberGenerator *prng) : prng(prng) {}

        DDD::ValueObjects::PlaintextPassword getRandomPassword(DDD::ValueObjects::PasswordLength pwLength) {
            std::vector<std::string> charset = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "A", "B",
                                                "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "1", "2", "3", "4",
                                                "5", "6", "7", "8", "9", "0", "!", "\"", "§", "$", "%", "&", "/", "(", ")", "=", "?", "{", "}", "[", "]", "\\", "+", "*", "~", "#", "'", "-",
                                                "_", ".", ":", ",", ";", "<", ">", "|"};
            std::string passwordString;
            for (unsigned int i = 0; i < pwLength.getInt(); ++i) {
                unsigned int index = prng->nextUInt(charset.size() - 1);
                passwordString += charset.at(index);
            }
            return DDD::ValueObjects::PlaintextPassword(passwordString);
        }

    private:
        PseudoRandomNumberGenerator *prng;
    };
}  // DDD::Services

#endif //SRC_PASSWORDGENERATOR_H
