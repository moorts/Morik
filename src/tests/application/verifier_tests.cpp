#include <gtest/gtest.h>
#include "AbstractDatabaseInterfaceMock.h"
#include "../../application/EntryRepository.h"
#include "../../application/PasswordVerifier.h"
#include "../../application/InstanceManager.h"
#include "../../plugins/encryption/DefaultHash.h"
#include "../../application/Hash.h"
#include <stdexcept>

using namespace DDD;

ACTION(ThrowDomainError) {
    throw std::domain_error("");
}

TEST(SetMasterPassword, DDDTests) {
    AbstractDatabaseInterfaceMock mock;

    Hash* hash = new DefaultHash();

    std::string masterPassword("masterPassword");
    ValueObjects::PlaintextPassword plainMasterPassword(masterPassword);

    ValueObjects::EncryptedPassword hashedPassword(hash->compute(hash->compute(masterPassword)));

    Services::MasterPasswordVerifier verifier(hash);

    const DatabaseColumn c = DatabaseColumn::EncryptedPassword;

    ValueObjects::EntryId id(0);

    Entities::Entry e(id, ValueObjects::EntryName("masterPasswordHash"), ValueObjects::Login("master"), hashedPassword);

    Repositories::EntryRepository* repo = new Repositories::EntryRepository(&mock);
    InstanceManager::addPointers(repo, nullptr, nullptr);

    EXPECT_CALL(mock, getEntry(id)).Times(2).WillOnce(testing::Throw(std::domain_error(""))).WillOnce(Return(e));
    EXPECT_CALL(mock, insertEntry(e)).Times(1);
    verifier.setMasterPassword(plainMasterPassword);

    EXPECT_TRUE(verifier.verifyMasterPassword(plainMasterPassword));
}

