#include <gtest/gtest.h>

#include "../../plugins/prng/MersenneTwister.h"
#include "../../application/PasswordGenerator.h"

TEST(PasswordGenerator, DDDTests) {
    MersenneTwister mt(0);
    DDD::Services::PasswordGenerator passwordGenerator(&mt);

    EXPECT_EQ(passwordGenerator.getRandomPassword().getString(), "Y3$\\4+Y\\M68JOB'f;zJR");
}
