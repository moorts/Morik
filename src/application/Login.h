#ifndef SRC_LOGIN_H
#define SRC_LOGIN_H

#include <string>

namespace DDD::ValueObjects {
    class Login final {
    public:
        Login(const std::string &login) : login(login) {}
        std::string getString() const { return login; }
        bool operator==(const Login &other) const { return other.login == login; }
    private:
        const std::string login;
    };
} // DDD::ValueObjects

#endif //SRC_LOGIN_H
