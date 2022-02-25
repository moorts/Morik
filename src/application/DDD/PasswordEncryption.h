#ifndef SRC_PASSWORDENCRYPTION_H
#define SRC_PASSWORDENCRYPTION_H

#include "../Cipher.h"
#include "EncryptedPassword.h"
#include "PlaintextPassword.h"

using namespace DDD;

namespace DDD::Services {
    class PasswordEncryptor {
    public:
        PasswordEncryptor(const Cipher* cipher, const ValueObjects::PlaintextPassword masterPassword) : cipher(cipher), masterPassword(masterPassword) {}
        ValueObjects::EncryptedPassword encrypt(DDD::ValueObjects::PlaintextPassword password) {
            return ValueObjects::EncryptedPassword(this->cipher->encrypt(password.getString(), this->masterPassword.getString()));
        }
    private:
        const Cipher* cipher;
        const ValueObjects::PlaintextPassword masterPassword;
    };

    class PasswordDecryptor {
    public:
        PasswordDecryptor(const Cipher* cipher, const ValueObjects::PlaintextPassword masterPassword) : cipher(cipher), masterPassword(masterPassword) {}
        ValueObjects::PlaintextPassword decrypt(ValueObjects::EncryptedPassword password) {
            return ValueObjects::PlaintextPassword(this->cipher->decrypt(password.getString(), this->masterPassword.getString()));
        }
    private:
        const Cipher* cipher;
        const ValueObjects::PlaintextPassword masterPassword;
    };
}

#endif // SRC_PASSWORDENCRYPTION_H

