//
// Created by moorts on 22.10.21.
//
#include <string>

#ifndef SRC_CIPHER_H
#define SRC_CIPHER_H

class Cipher {
public:
    virtual std::string encrypt(std::string plain, std::string master) const = 0;
    virtual std::string decrypt(std::string cipher, std::string master) const = 0;
};


#endif //SRC_CIPHER_H
