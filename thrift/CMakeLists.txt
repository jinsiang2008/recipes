cmake_minimum_required(VERSION 3.6)
project(thrift)

set(CMAKE_CXX_STANDARD 11)

set(CLIENT_FILES hello_client.cc)

set(SERVER_FILES hello_server.cc)

set(GEN_FILES
        "gen-cpp/HelloSvc.cpp"
        "gen-cpp/hello_constants.cpp"
        "gen-cpp/hello_types.cpp")

execute_process(COMMAND thrift --gen cpp hello.thrift
								WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

execute_process(COMMAND thrift --gen py hello.thrift
								WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(hello_client ${CLIENT_FILES} ${GEN_FILES})

add_executable(hello_server ${SERVER_FILES} ${GEN_FILES})

target_link_libraries(hello_client thrift)

target_link_libraries(hello_server thrift)

