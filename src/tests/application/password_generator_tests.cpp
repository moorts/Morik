#include <gtest/gtest.h>

#include "../../plugins/prng/MersenneTwister.h"
#include "../../application/PasswordGenerator.h"

TEST(PasswordGenerator, DDDTests) {
    MersenneTwister mt(666);
    DDD::Services::PasswordGenerator passwordGenerator(&mt);

    EXPECT_EQ(passwordGenerator.getRandomPassword(20).getString(), "§j\\t!l%(,EbwMxezjQUv");
}
