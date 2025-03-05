cmake_minimum_required(VERSION 3.10)
project(blockchain-cpp)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenSSL REQUIRED)

include_directories(${OPENSSL_INCLUDE_DIR})
include_directories(core)

add_executable(blockchain
    main.cpp
    core/src/block.cpp
    core/transaction.cpp
)

target_link_libraries(blockchain ${OPENSSL_LIBRARIES})
