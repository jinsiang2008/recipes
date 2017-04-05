cmake_minimum_required(VERSION 3.6)
project(thc)

message(STATUS "Generate redis client")
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES redis_client.cc redis_client.h)

add_executable(client ${SOURCE_FILES})

target_link_libraries(client hiredis event)
