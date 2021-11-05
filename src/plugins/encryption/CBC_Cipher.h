//
// Created by moorts on 28.10.21.
//

#ifndef SRC_CBC_CIPHER_H
#define SRC_CBC_CIPHER_H

#include "Cipher.h"
#include "BLOCK.h"
#include <cryptopp/cryptlib.h>
#include <cryptopp/rijndael.h>
#include <cryptopp/serpent.h>
#include <cryptopp/modes.h>
#include <cryptopp/osrng.h>
#include <cryptopp/files.h>
#include <cryptopp/hex.h>

class CBC_Cipher : public Cipher {
public:
    CBC_Cipher(BLOCK b) {
        this->b = b;
    }

    std::string encrypt(std::string plain, SecByteBlock key) const;

    std::string decrypt(std::string cipher, SecByteBlock key) const;

private:
    BLOCK b;
};


#endif //SRC_CBC_CIPHER_H
