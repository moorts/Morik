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
    HexDecoder decoder;

    std::string c;
    c.resize(cipher.size()/2-AES::BLOCKSIZE);
    SecByteBlock iv(AES::BLOCKSIZE);

    decoder.Put((byte*)&cipher[0], cipher.size());

    decoder.Get(iv, AES::BLOCKSIZE);

    decoder.Get((byte*)&c[0], c.size());

    std::string plain;

    try {
        CBC_Mode< AES >::Decryption d;
        d.SetKeyWithIV(this->key, this->key.size(), iv);

        StringSource s(c, true,
            new StreamTransformationFilter(d,
                new StringSink(plain)));
    } catch(const Exception& e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }

    return plain;
}

std::string Cipher::encrypt(std::string plain) {
    AutoSeededRandomPool prng;
    HexEncoder encoder(NULL);


    SecByteBlock iv(AES::BLOCKSIZE);

    prng.GenerateBlock(iv, iv.size());


    std::string cipher;

    try {
        CBC_Mode< AES >::Encryption e;
        e.SetKeyWithIV(this->key, this->key.size(), iv);

        StringSource s(plain, true,
            new StreamTransformationFilter(e,
                new StringSink(cipher)
            )
        );
    } catch(const Exception& e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }

    encoder.Put(iv, iv.size());
    encoder.Put((const byte*)&cipher[0], cipher.size());

    std::string out;
    word64 size = encoder.MaxRetrievable();
    out.resize(size);
    encoder.Get((byte*)&out[0], out.size());

    return out;
}