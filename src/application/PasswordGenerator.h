#ifndef SRC_PASSWORDGENERATOR_H
#define SRC_PASSWORDGENERATOR_H

#include "PseudoRandomNumberGenerator.h"
#include "PlaintextPassword.h"

class PasswordGenerator {
public:
    PasswordGenerator(const PseudoRandomNumberGenerator* prng) : prng(prng) {}
    DDD::ValueObjects::PlaintextPassword getRandomPassword() const {
        std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!\"§$%&/()=?{}[]\\+*~#'-_.:,;<>|";
        std::string passwordString = "";
        for (int i = 0; i < 20; ++i) {
            int index = prng->nextInt();
            passwordString += charset.at(index);
        }
        return DDD::ValueObjects::PlaintextPassword(passwordString);
    }
private:
    const PseudoRandomNumberGenerator* prng;
};


#endif //SRC_PASSWORDGENERATOR_H
