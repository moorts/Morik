//
// Created by moorts on 22.10.21.
//
#include <string>

#ifndef SRC_CIPHER_H
#define SRC_CIPHER_H


class Cipher {
    std::string encrypt(std::string plain);

    std::string decrypt(std::string cipher);
};


#endif //SRC_CIPHER_H
