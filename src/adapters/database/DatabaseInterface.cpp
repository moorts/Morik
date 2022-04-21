#include "DatabaseInterface.h"
#include <stdexcept>

using namespace Adapters::Database;

DDD::Entities::Entry DatabaseInterface::getEntry(const DDD::ValueObjects::EntryId &entryId) const
{
    std::string sql = "SELECT * FROM passwords WHERE EntryId = \"" + std::to_string(entryId.getInt()) + "\";";
    auto [entrySet, error] = db->executeSql(sql);
    if (!entrySet.empty())
        return *entrySet.begin();
    throw std::domain_error("no Entry with provided ID");
}

std::set<DDD::Entities::Entry> DatabaseInterface::getEntries(const DDD::ValueObjects::EntryName &entryName) const
{
    std::string sql = "SELECT * FROM passwords WHERE EntryName LIKE \"%" + entryName.getString() + "%\";";
    auto [entrySet, error] = db->executeSql(sql);
    return entrySet;
}

std::set<DDD::Entities::Entry> DatabaseInterface::getAllEntries() const
{
    std::string sql = "SELECT * FROM passwords WHERE EntryId <> 0;";
    auto [entrySet, error] = db->executeSql(sql);
    return entrySet;
}

bool DatabaseInterface::insertEntry(const DDD::Entities::Entry &entry) const
{
    std::string sql = "INSERT INTO passwords VALUES(\"" + std::to_string(entry.getEntryId().getInt()) + "\",\"" + entry.entryName.getString() + "\",\"" + entry.login.getString() + "\",\"" + entry.encryptedPassword.getString() + "\");";
    auto [entrySet, error] = db->executeSql(sql);
    return performErrorCheck(error);
}

bool DatabaseInterface::removeEntry(const DDD::ValueObjects::EntryId &entryId) const
{
    std::string sql = "DELETE FROM passwords WHERE EntryId = \"" + std::to_string(entryId.getInt()) + "\";";
    auto [entrySet, error] = db->executeSql(sql);
    return performErrorCheck(error);
}

bool DatabaseInterface::modifyEntry(const DDD::ValueObjects::EntryId &entryId, const DatabaseColumn &column, const std::string &newValue) const
{
    std::string columnString = getDatabaseColumnString(column);
    std::string sql = "UPDATE passwords SET " + columnString + " = \"" + newValue + "\" WHERE EntryId = \"" + std::to_string(entryId.getInt()) + "\";";
    auto [entrySet, error] = db->executeSql(sql);
    return performErrorCheck(error);
}

bool DatabaseInterface::performErrorCheck(std::string errorString) const
{
    if (!errorString.empty())
    {
        return false;
    }
    return true;
}
