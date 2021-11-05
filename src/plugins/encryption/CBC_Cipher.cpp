//
// Created by moorts on 05.11.21.
//

#include "CBC_Cipher.h"

std::string CBC_Cipher::encrypt(std::string plain, SecByteBlock key) const {
    AutoSeededRandomPool prng;
    HexEncoder encoder(nullptr);

    SecByteBlock iv(AES::BLOCKSIZE);

    prng.GenerateBlock(iv, iv.size());

    std::string cipher;

    try {
        switch (this->b) {
            case BLOCK::AES: {
                CBC_Mode<CryptoPP::AES>::Encryption e;
                e.SetKeyWithIV(key, key.size(), iv);

                StringSource s(plain, true,
                               new StreamTransformationFilter(e,
                                                              new StringSink(cipher)
                               )
                );
                break;
            }
            case BLOCK::Serpent: {
                CBC_Mode<CryptoPP::Serpent>::Encryption e;
                e.SetKeyWithIV(key, key.size(), iv);

                StringSource s(plain, true,
                               new StreamTransformationFilter(e,
                                                              new StringSink(cipher)
                               )
                );
                break;
            }
        }
    } catch (const Exception &e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }

    encoder.Put(iv, iv.size());
    encoder.Put((const byte *) &cipher[0], cipher.size());

    std::string out;
    word64 size = encoder.MaxRetrievable();
    out.resize(size);
    encoder.Get((byte *) &out[0], out.size());

    return out;
}

std::string CBC_Cipher::decrypt(std::string cipher, SecByteBlock key) const {
    HexDecoder decoder;

    std::string c;
    c.resize(cipher.size() / 2 - AES::BLOCKSIZE);
    SecByteBlock iv(AES::BLOCKSIZE);

    decoder.Put((byte *) &cipher[0], cipher.size());

    decoder.Get(iv, AES::BLOCKSIZE);

    decoder.Get((byte *) &c[0], c.size());

    std::string plain;

    try {
        switch (this->b) {
            case BLOCK::AES: {
                CBC_Mode<CryptoPP::AES>::Decryption d;
                d.SetKeyWithIV(key, key.size(), iv);

                StringSource s(c, true,
                               new StreamTransformationFilter(d,
                                                              new StringSink(plain)));
                break;
            }
            case BLOCK::Serpent: {
                CBC_Mode<CryptoPP::Serpent>::Decryption d;
                d.SetKeyWithIV(key, key.size(), iv);

                StringSource s(c, true,
                               new StreamTransformationFilter(d,
                                                              new StringSink(plain)));
                break;
            }
        }
    } catch (const Exception &e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }

    return plain;
}

