cmake_minimum_required(VERSION 3.16)
project(src)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)

include(CTest)
enable_testing()

set(SOURCE_FILES application/Cipher.h plugins/encryption/DefaultHash.h plugins/encryption/CBC_Cipher.h plugins/encryption/BLOCK.h adapters/database/DatabaseInterface.cpp adapters/database/DatabaseInterface.h plugins/database/SQLiteDatabase.cpp plugins/database/SQLiteDatabase.h adapters/database/AbstractSqlDatabase.h plugins/encryption/CBC_Cipher.cpp application/PlaintextPassword.h application/EncryptedPassword.h application/EntryName.h application/Login.h application/Entry.h application/EntryRepository.cpp application/EntryRepository.h application/EntryId.h application/EntryFactory.h application/EntryFactory.cpp application/Hash.h application/DatabaseColumn.h application/PasswordEncryption.h application/MasterPasswordVerifier.h application/InstanceManager.h application/InstanceManager.cpp application/AbstractDatabaseInterface.h adapters/ui/UiDataHelper.cpp adapters/ui/UiDataHelper.h application/AbstractUserInterface.h plugins/ui/CommandLineInterface.cpp plugins/ui/CommandLineInterface.h application/PasswordGenerator.h application/PseudoRandomNumberGenerator.h plugins/prng/MersenneTwister.cpp plugins/prng/MersenneTwister.h application/PasswordLength.h)

add_executable(src main.cpp ${SOURCE_FILES})
target_link_libraries(src sqlite3 cryptopp)

add_executable(test_main tests/test_main.cpp ${SOURCE_FILES})
target_compile_options(test_main PUBLIC "-O0" "-fprofile-arcs" "-ftest-coverage")
target_link_options(test_main PUBLIC "-fprofile-arcs" "-ftest-coverage")
target_link_libraries(test_main sqlite3 cryptopp gtest_main gmock_main)

include(GoogleTest)
gtest_discover_tests(test_main)
