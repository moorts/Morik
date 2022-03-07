cmake_minimum_required(VERSION 3.16)
project(src)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(src main.cpp application/Cipher.h plugins/encryption/KeyDerivation.h plugins/encryption/CBC_Cipher.h plugins/encryption/BLOCK.h application/DbInterface.cpp application/DbInterface.h plugins/database/SQLiteDatabase.cpp plugins/database/SQLiteDatabase.h application/AbstractDatabase.h plugins/encryption/CBC_Cipher.cpp)
target_link_libraries(src sqlite3 cryptopp)

add_executable(test_main tests/test_main.cpp)
target_link_libraries(test_main sqlite3 cryptopp gtest_main)

include(GoogleTest)
gtest_discover_tests(test_main)
