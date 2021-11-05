//
// Created by moorts on 28.10.21.
//

#ifndef SRC_ENCRYPTIONINTERFACE_H
#define SRC_ENCRYPTIONINTERFACE_H

#include "../plugins/encryption/KeyDerivation.h"


class EncryptionInterface {
public:
    EncryptionInterface(const Cipher* cipher) {
        this->c = cipher;
    }

    std::string encrypt(std::string pw, std::string master) const {
        return this->c->encrypt(pw, KeyDerivation::derive(master));
    }

    std::string decrypt(std::string cipher, std::string master) const {
        return this->c->decrypt(cipher, KeyDerivation::derive(master));
    }

private:
    const Cipher* c;

};


#endif //SRC_ENCRYPTIONINTERFACE_H