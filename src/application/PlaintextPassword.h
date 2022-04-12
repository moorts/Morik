#ifndef SRC_PLAINTEXTPASSWORD_H
#define SRC_PLAINTEXTPASSWORD_H

#include <string>

namespace DDD::ValueObjects {
    class PlaintextPassword final {
    public:
        PlaintextPassword(const std::string &plaintext) : plaintext(plaintext) {}
        std::string getString() const { return plaintext; }
        bool operator==(const PlaintextPassword &other) const { return other.plaintext == plaintext; }
    private:
        const std::string plaintext;
    };
} // DDD::ValueObjects

#endif //SRC_PLAINTEXTPASSWORD_H
