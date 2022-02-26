#include "DbInterface.h"

using namespace Adapters::Database;

DDD::Entities::Entry DbInterface::getEntry(const DDD::ValueObjects::EntryId &entryId) const
{
    std::string sql = "SELECT * FROM passwords WHERE EntryId = \"" + std::to_string(entryId.getInt()) + "\";";
    auto [entrySet, error] = db->executeSql(sql);
    return *entrySet.begin();
}

std::set<DDD::Entities::Entry> DbInterface::getEntries(const DDD::ValueObjects::EntryName &entryName) const
{
    std::string sql = "SELECT * FROM passwords WHERE EntryName = \"" + entryName.getString() + "\";";
    auto [entrySet, error] = db->executeSql(sql);
    return entrySet;
}

std::set<DDD::Entities::Entry> DbInterface::getAllEntries() const
{
    std::string sql = "SELECT * FROM passwords;";
    auto [entrySet, error] = db->executeSql(sql);
    return entrySet;
}

bool DbInterface::insertEntry(const DDD::Entities::Entry &entry) const
{
    std::string sql = "INSERT INTO passwords VALUES(\"" + std::to_string(entry.getEntryId().getInt()) + "\",\"" + entry.entryName.getString() + "\",\"" + entry.login.getString() + "\",\"" + entry.encryptedPassword.getString() + "\");";
    auto [entrySet, error] = db->executeSql(sql);
    if (!error.empty())
    {
        return false;
    }
    return true;
}

bool DbInterface::removeEntry(const DDD::ValueObjects::EntryId &entryId) const
{
    std::string sql = "DELETE FROM passwords WHERE EntryId = \"" + std::to_string(entryId.getInt()) + "\";";
    auto [entrySet, error] = db->executeSql(sql);
    if (!error.empty())
    {
        return false;
    }
    return true;
}

bool DbInterface::modifyEntry(const DDD::ValueObjects::EntryId &entryId, const DatabaseColumn &column, const std::string &newValue) const
{
    std::string columnString = getDatabaseColumnString(column);
    std::string sql = "UPDATE passwords SET " + columnString + " = \"" + newValue + "\" WHERE EntryId = \"" + std::to_string(entryId.getInt()) + "\";";
    auto [entrySet, error] = db->executeSql(sql);
    if (!error.empty())
    {
        return false;
    }
    return true;
}
