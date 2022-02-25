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
        ValueObjects::EncryptedPassword encrypt(DDD::ValueObjects::PlaintextPassword plaintextPassword) const {
            return ValueObjects::EncryptedPassword(this->cipher->encrypt(plaintextPassword.getString(), this->masterPassword.getString()));
        }
    private:
        const Cipher* cipher;
        const ValueObjects::PlaintextPassword masterPassword;
    };

    class PasswordDecryptor {
    public:
        PasswordDecryptor(const Cipher* cipher, const ValueObjects::PlaintextPassword masterPassword) : cipher(cipher), masterPassword(masterPassword) {}
        ValueObjects::PlaintextPassword decrypt(ValueObjects::EncryptedPassword encryptedPassword) const {
            return ValueObjects::PlaintextPassword(this->cipher->decrypt(encryptedPassword.getString(), this->masterPassword.getString()));
        }
    private:
        const Cipher* cipher;
        const ValueObjects::PlaintextPassword masterPassword;
    };
}

#endif // SRC_PASSWORDENCRYPTION_H

