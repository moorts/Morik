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
    Cipher() {
        AutoSeededRandomPool prng;

        this->key = SecByteBlock(AES::BLOCKSIZE);

        prng.GenerateBlock(key, key.size());
    }

    std::string encrypt(std::string plain);

    std::string decrypt(std::string cipher);

private:
    SecByteBlock key;
};


#endif //SRC_CIPHER_H
