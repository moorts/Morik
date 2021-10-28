cmake_minimum_required(VERSION 3.20)
project(src)

SET(GCC_COVERAGE_LINK_FLAGS    "-lcryptopp")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

set(CMAKE_CXX_STANDARD 20)

add_executable(src main.cpp encryption/Cipher.h encryption/PasswordEncryptionHandler.h encryption/KeyDerivation.h encryption/Encryption.h encryption/CBC_Cipher.h encryption/BLOCK.h application/DbInterface.cpp application/DbInterface.h plugins/database/SQLiteDatabase.cpp plugins/database/SQLiteDatabase.h application/AbstractDatabase.h)
target_link_libraries(src sqlite3)
