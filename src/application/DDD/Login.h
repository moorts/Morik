#ifndef SRC_LOGIN_H
#define SRC_LOGIN_H

#include <string>

namespace DDD::ValueObjects {
    class Login final {
    public:
        Login(const std::string &name) : name(name) {}
        std::string getPlaintext() { return name; }
        bool operator==(const Login &other) const { return other.name == name; }
    private:
        const std::string name;
    };
} // DDD::ValueObjects

#endif //SRC_LOGIN_H
