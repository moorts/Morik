//
// Created by moorts on 22.10.21.
//

#include "Cipher.h"
#include <cryptopp/cryptlib.h>
#include <cryptopp/rijndael.h>
#include <cryptopp/modes.h>
#include <cryptopp/osrng.h>
#include <cryptopp/files.h>
#include <cryptopp/hex.h>

using namespace CryptoPP;

std::string Cipher::decrypt(std::string cipher) {
}

std::string Cipher::encrypt(std::string plain) {
    AutoSeededRandomPool prng;

    SecByteBlock key(AES::DEFAULT_KEYLENGTH);
    SecByteBlock iv(AES::BLOCKSIZE);

    prng.GenerateBlock(key, key.size());
    prng.GenerateBlock(iv, iv.size());

    std::string cipher;

    try {
        CBC_Mode< AES >::Encryption e;
        e.SetKeyWithIV(key, key.size(), iv);

        StringSource s(plain, true,
            new StreamTransformationFilter(e,
                new StringSink(cipher)
            )
        );
    } catch(const Exception& e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }

    return cipher;
}