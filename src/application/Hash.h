#ifndef SRC_HASH_H
#define SRC_HASH_H

class Hash {
public:
    virtual std::string compute(std::string plain) const = 0;
};

#endif
