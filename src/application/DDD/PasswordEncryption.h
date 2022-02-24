#ifndef SRC_PASSWORDENCRYPTION_H
#define SRC_PASSWORDENCRYPTION_H

#include "../Cipher.h"
#include "EncryptedPassword.h"
#include "PlaintextPassword.h"

using namespace DDD;

namespace DDD::Services {
    class PasswordEncryptor {
    public:
        PasswordEncryptor(const Cipher* cipher) : cipher(cipher) {}
        ValueObjects::EncryptedPassword encrypt(DDD::ValueObjects::PlaintextPassword password, std::string master) {
            return ValueObjects::EncryptedPassword(this->cipher->encrypt(password.getString(), master));
        }
    private:
        const Cipher* cipher;
    };

    class PasswordDecryptor {
    public:
        PasswordDecryptor(const Cipher* cipher) : cipher(cipher) {}
        ValueObjects::PlaintextPassword decrypt(ValueObjects::EncryptedPassword password, std::string master) {
            return ValueObjects::PlaintextPassword(this->cipher->decrypt(password.getString(), master));
        }
    private:
        const Cipher* cipher;
    };
}

#endif // SRC_PASSWORDENCRYPTION_H

