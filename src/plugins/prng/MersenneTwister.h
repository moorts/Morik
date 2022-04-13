#ifndef SRC_MERSENNETWISTER_H
#define SRC_MERSENNETWISTER_H

#include "../../application/PseudoRandomNumberGenerator.h"
#include <random>

class MersenneTwister : public PseudoRandomNumberGenerator {
public:
    MersenneTwister();
    int nextInt(int max) const;
private:
    std::mt19937 mt;
};


#endif //SRC_MERSENNETWISTER_H
