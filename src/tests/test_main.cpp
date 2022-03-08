#include <gtest/gtest.h>

#include "./plugins/encryption/crypto_tests.cpp"
#include "./application/DDD/encryptor_tests.cpp"

TEST(HelloTest, BasicAssertions) {
    EXPECT_STRNE("Hello", "world");

    EXPECT_EQ(7*6, 42);
}
