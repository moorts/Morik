#include <gtest/gtest.h>

#include "../../../plugins/encryption/CBC_Cipher.h"
#include "../../../plugins/encryption/BLOCK.h"

TEST(AESEncryption, PluginTests) {
    CBC_Cipher* c = new CBC_Cipher(BLOCK::AES);

    std::string plain = "Plaintext";
    std::string master = "MasterKey";
    std::string encrypted = c->encrypt(plain, master);

    std::string decrypted = c->decrypt(encrypted, master);

    // Check that encryption happened
    EXPECT_NE(plain, encrypted);
    // Check that decryption worked
    EXPECT_EQ(plain, decrypted);
}

TEST(SerpentEncryption, PluginTests) {
    CBC_Cipher* c = new CBC_Cipher(BLOCK::Serpent);

    std::string plain = "Plaintext";
    std::string master = "MasterKey";
    std::string encrypted = c->encrypt(plain, master);

    std::string decrypted = c->decrypt(encrypted, master);
    
    // Check that encryption happened
    EXPECT_NE(plain, encrypted);
    // Check that decryption worked
    EXPECT_EQ(plain, decrypted);
}
