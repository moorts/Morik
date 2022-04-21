#ifndef SRC_ENTRYNAME_H
#define SRC_ENTRYNAME_H

#include <string>

namespace DDD::ValueObjects {
    class EntryName final {
    public:
        EntryName(const std::string &name) : name(name) {}
        std::string getString() const { return name; }
        bool operator==(const EntryName &other) const { return other.name == name; }
        bool operator<(const EntryName &other) const { return name < other.name; }
    private:
        const std::string name;
    };
} // DDD::ValueObjects

#endif //SRC_ENTRYNAME_H
