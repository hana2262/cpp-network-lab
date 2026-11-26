cmake_minimum_required(VERSION 3.20)
project(cpp_network_lab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(connect_server exercises/n01-connect/server.cpp)
add_executable(connect_client exercises/n01-connect/client.cpp)

target_compile_options(connect_server PRIVATE -Wall -Wextra -Wpedantic)
target_compile_options(connect_client PRIVATE -Wall -Wextra -Wpedantic)
