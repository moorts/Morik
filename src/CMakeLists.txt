cmake_minimum_required(VERSION 3.20)
project(src)

set(CMAKE_CXX_STANDARD 20)

add_executable(src main.cpp application/Cipher.h plugins/encryption/KeyDerivation.h plugins/encryption/CBC_Cipher.h plugins/encryption/BLOCK.h application/DbInterface.cpp application/DbInterface.h plugins/database/SQLiteDatabase.cpp plugins/database/SQLiteDatabase.h application/AbstractDatabase.h plugins/encryption/CBC_Cipher.cpp application/DDD/PlaintextPassword.h application/DDD/EncryptedPassword.h application/DDD/EntryName.h application/DDD/Login.h application/DDD/Entry.h application/DDD/EntryRepository.cpp application/DDD/EntryRepository.h application/DDD/EntryId.h application/DDD/EntryFactory.h application/DDD/EntryFactory.cpp application/DatabaseColumn.h)
target_link_libraries(src sqlite3 cryptopp)
