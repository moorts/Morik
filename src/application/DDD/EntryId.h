#ifndef SRC_ENTRYID_H
#define SRC_ENTRYID_H

namespace DDD::ValueObjects {
    class EntryId final {
    public:
        EntryId(const unsigned int &id) : id(id) {}
        unsigned int getId() { return id; }
        bool operator==(const EntryId &other) const { return other.id == id; }
    private:
        const unsigned int id;
    };
} // DDD::ValueObjects

#endif //SRC_ENTRYID_H
