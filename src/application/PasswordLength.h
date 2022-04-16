#ifndef SRC_PASSWORDLENGTH_H
#define SRC_PASSWORDLENGTH_H

namespace DDD::ValueObjects {
    class PasswordLength final {
    public:
        PasswordLength(const unsigned int &length) : length(length) {}
        unsigned int getInt() const { return length; }
        bool operator==(const PasswordLength &other) const { return other.length == length; }
    private:
        const unsigned int length;
    };
} // DDD::ValueObjects

#endif //SRC_PASSWORDLENGTH_H
