cmake_minimum_required(VERSION 3.3)
project(memory_cli)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Runner.h Runner.cpp dbhandler.h dbhandler.cpp)

add_executable(memory_cli ${SOURCE_FILES})
target_link_libraries(memory_cli sqlite3)
