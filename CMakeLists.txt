cmake_minimum_required(VERSION 3.10)
project(BlockchainSimulation)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})
include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(BlockchainSimulation ${SOURCES})
target_link_libraries(BlockchainSimulation OpenSSL::SSL OpenSSL::Crypto)
