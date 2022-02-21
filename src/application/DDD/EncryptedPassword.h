#ifndef SRC_ENCRYPTEDPASSWORD_H
#define SRC_ENCRYPTEDPASSWORD_H

#include <string>

namespace DDD::ValueObjects {
    class EncryptedPassword final {
    public:
        EncryptedPassword(const std::string &encrypted) : encrypted(encrypted) {}
        std::string getPlaintext() { return encrypted; }
        bool operator==(const EncryptedPassword &other) const { return other.encrypted == encrypted; }
    private:
        const std::string encrypted;
    };
} // namespace DDD::ValueObjects

#endif //SRC_ENCRYPTEDPASSWORD_H
