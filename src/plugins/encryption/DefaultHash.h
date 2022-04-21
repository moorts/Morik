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
        HexEncoder hexEncoder(nullptr);
        SecByteBlock hash = Sha256::calculate(plain);
        std::string out;
        hexEncoder.Put(hash, hash.size());
        word64 size = hexEncoder.MaxRetrievable();
        out.resize(size);
        hexEncoder.Get((byte*) &out[0], out.size());
        return out;
    }
};


#endif //SRC_KEYDERIVATION_H
