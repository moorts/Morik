//
// Created by moorts on 25.10.21.
//

#ifndef SRC_DEFAULTHASH_H
#define SRC_DEFAULTHASH_H

#include <cryptopp/sha.h>
#include <cryptopp/cryptlib.h>

#include "../../application/Hash.h"

class Sha256 {
public:
    static SecByteBlock calculate(std::string plain) {
        using namespace CryptoPP;

        SHA256 hash;
        hash.Update((const byte*) plain.data(), plain.size());

        SecByteBlock result(hash.DigestSize());
        hash.Final(result);
        return result;
    }
};

class DefaultHash : public Hash {
public:
    std::string compute(std::string plain) const {
        SecByteBlock hash = Sha256::calculate(plain);
        return std::string((const char*) hash.data(), hash.size());
    }
};


#endif //SRC_KEYDERIVATION_H
