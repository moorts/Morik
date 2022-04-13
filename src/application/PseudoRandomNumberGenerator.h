#ifndef SRC_PSEUDORANDOMNUMBERGENERATOR_H
#define SRC_PSEUDORANDOMNUMBERGENERATOR_H

class PseudoRandomNumberGenerator {
public:
    virtual int nextInt(int max) const = 0;
};

#endif //SRC_PSEUDORANDOMNUMBERGENERATOR_H
