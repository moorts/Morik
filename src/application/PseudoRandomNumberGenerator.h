#ifndef SRC_PSEUDORANDOMNUMBERGENERATOR_H
#define SRC_PSEUDORANDOMNUMBERGENERATOR_H

class PseudoRandomNumberGenerator {
public:
    virtual unsigned int nextUInt(unsigned int max) = 0;
};

#endif //SRC_PSEUDORANDOMNUMBERGENERATOR_H
