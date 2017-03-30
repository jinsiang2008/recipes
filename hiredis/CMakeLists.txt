cmake_minimum_required(VERSION 3.6)
project(thc)

message(STATUS "Wilbeibi compiling")
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES redis_client.cc redis_client.h)

add_executable(demo ${SOURCE_FILES})

target_link_libraries(demo hiredis event)
