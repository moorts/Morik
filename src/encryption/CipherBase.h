//
// Created by moorts on 25.10.21.
//

#ifndef SRC_CIPHERBASE_H
#define SRC_CIPHERBASE_H

#include <iostream>

class CipherBase {
public:
    static std::string encrypt(std::string plain) {
        std::cout << "CipherBase encryption" << std::endl;
        return "";
    }

    static std::string decrypt(std::string cipher) {
        std::cout << "CipherBase decryption" << std::endl;
        return "";
    }
};


#endif //SRC_CIPHERBASE_H
