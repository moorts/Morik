//
// Created by moorts on 22.10.21.
//
#include <string>
#include <cryptopp/modes.h>
#include <cryptopp/osrng.h>

#include <iostream>

#ifndef SRC_CIPHER_H
#define SRC_CIPHER_H

using namespace CryptoPP;

class Cipher {
public:
    virtual std::string encrypt(std::string plain, SecByteBlock* key) const {
        std::cerr << "This should not be called, ever" << std::endl;
        return NULL;
    }

    virtual std::string decrypt(std::string cipher, SecByteBlock* key) const {
        std::cerr << "This should not be called, ever" << std::endl;
        return NULL;
    }
};


#endif //SRC_CIPHER_H
