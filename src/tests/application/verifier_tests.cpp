#include <gtest/gtest.h>
#include "AbstractDatabaseInterfaceMock.h"
#include "../../application/EntryRepository.h"
#include "../../application/MasterPasswordVerifier.h"
#include "../../application/InstanceManager.h"
#include "../../plugins/encryption/DefaultHash.h"
#include "../../application/Hash.h"
#include "../../adapters/ui/UiDataHelper.h"
#include "../../plugins/ui/CommandLineInterface.h"
#include <stdexcept>

using namespace DDD;

ACTION(ThrowDomainError) {
    throw std::domain_error("");
}

TEST(VerifyMasterPassword, DDDTests) {
    AbstractDatabaseInterfaceMock mock;

    std::string masterPassword("masterPassword");

    Adapters::UI::UiDataHelper uiDataHelper;
    Plugins::UI::CommandLineInterface cli(uiDataHelper);
    Hash* hash = new DefaultHash();
    Services::MasterPasswordVerifier verifier(hash, &cli);
    ValueObjects::EncryptedPassword hashedPassword(hash->compute(hash->compute(masterPassword)));

    ValueObjects::EntryId id(0);
    Entities::Entry e(id, ValueObjects::EntryName("masterPasswordHash"), ValueObjects::Login("master"), hashedPassword);

    EXPECT_CALL(mock, getEntry(id)).Times(2).WillOnce(testing::Throw(std::domain_error(""))).WillOnce(Return(e));
    EXPECT_CALL(mock, insertEntry(e)).Times(1);


    Repositories::EntryRepository* repo = new Repositories::EntryRepository(&mock);
    InstanceManager::addEntryRepositoryPointer(repo);

    ValueObjects::PlaintextPassword plainMasterPassword(masterPassword);
    verifier.setMasterPassword(plainMasterPassword);

    EXPECT_TRUE(verifier.verifyMasterPassword(plainMasterPassword));
}

