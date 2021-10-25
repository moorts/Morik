//
// Created by moorts on 25.10.21.
//

#ifndef SRC_PASSWORDENCRYPTIONHANDLER_H
#define SRC_PASSWORDENCRYPTIONHANDLER_H

#include "KeyDerivation.h"

template <class C>
concept CIPHER = requires(C) {
    { C::encrypt(NULL, NULL) } -> std::same_as<std::string>;
    { C::decrypt(NULL, NULL) } -> std::same_as<std::string>;
};

template <CIPHER C>
class PasswordEncryptionHandler {
public:
    static std::string encryptPassword(std::string pw, std::string master) {
        return C::encrypt(pw, KeyDerivation::derive(master));
    }
    static std::string decryptPassword(std::string cipher, std::string master) {
        return C::decrypt(cipher, KeyDerivation::derive(master));
    }
};


#endif //SRC_PASSWORDENCRYPTIONHANDLER_H
