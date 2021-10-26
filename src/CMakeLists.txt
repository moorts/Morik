cmake_minimum_required(VERSION 3.20)
project(src)

set(CMAKE_CXX_STANDARD 20)

add_executable(src main.cpp application/DbInterface.cpp application/DbInterface.h plugins/database/SQLiteDatabase.cpp plugins/database/SQLiteDatabase.h application/Database.h)
target_link_libraries(src sqlite3)
