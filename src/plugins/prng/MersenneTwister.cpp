#include "MersenneTwister.h"

MersenneTwister::MersenneTwister(unsigned int seed)
{
    std::mt19937 mersenneTwister(seed);
    mt = mersenneTwister;
}

unsigned int MersenneTwister::nextUInt(unsigned int max)
{
    std::uniform_int_distribution<std::mt19937::result_type> distribution(0, max);
    return distribution(mt);
}
