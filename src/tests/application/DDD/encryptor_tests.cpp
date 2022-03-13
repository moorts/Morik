#include <gtest/gtest.h>
#include "../../../application/DDD/PasswordEncryption.h"
#include "../../../application/Cipher.h"
#include "../../../plugins/encryption/CBC_Cipher.h"
#include "../../../plugins/encryption/BLOCK.h"

using namespace DDD::Services;
using namespace DDD::ValueObjects;

TEST(PasswordEncryptionService, DDDTests) {
    const Cipher* cipher = new CBC_Cipher(BLOCK::AES);

    const PlaintextPassword masterPassword = PlaintextPassword("Masterkey");
    PasswordEncryptor passwordEncryptor = PasswordEncryptor(cipher, masterPassword);

    const PlaintextPassword plaintext = PlaintextPassword("Plaintext");
    const ValueObjects::EncryptedPassword ciphertext = passwordEncryptor.encrypt(plaintext);

    PasswordDecryptor passwordDecryptor = PasswordDecryptor(cipher, masterPassword);
    const PlaintextPassword decryptedCiphertext = passwordDecryptor.decrypt(ciphertext);

    EXPECT_EQ(plaintext.getString(), decryptedCiphertext.getString());
}
