//
// Created by moorts on 25.10.21.
//

#ifndef SRC_KEYDERIVATION_H
#define SRC_KEYDERIVATION_H

#include <cryptopp/sha.h>
#include <cryptopp/cryptlib.h>

class KeyDerivation {
public:
    static SecByteBlock derive(std::string master) {
        using namespace CryptoPP;

        SHA256 hash;
        hash.Update((const byte*) master.data(), master.size());

        SecByteBlock key(hash.DigestSize());
        hash.Final(key);
        return key;
    }
};


#endif //SRC_KEYDERIVATION_H
