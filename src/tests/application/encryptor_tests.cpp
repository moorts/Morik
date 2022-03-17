#include "../../cmake-build-debug/_deps/googletest-src/googletest/include/gtest/gtest.h"
#include "../../application/PasswordEncryption.h"
#include "../../application/Cipher.h"
#include "../../plugins/encryption/CBC_Cipher.h"
#include "../../plugins/encryption/BLOCK.h"

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

    // Check that encryption happened
    EXPECT_NE(plaintext.getString(), ciphertext.getString());
    // Check that decryption worked
    EXPECT_EQ(plaintext.getString(), decryptedCiphertext.getString());
}
