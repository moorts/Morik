#ifndef SRC_USERNAME_H
#define SRC_USERNAME_H

#include <string>

namespace DDD::ValueObjects {
    class Username final {
    public:
        Username(const std::string &name) : name(name) {}
        std::string getPlaintext() { return name; }
        bool operator==(const Username &other) const { return other.name == name; }
    private:
        const std::string name;
    };
} // DDD::ValueObjects

#endif //SRC_USERNAME_H
