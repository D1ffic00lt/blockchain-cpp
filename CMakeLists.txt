cmake_minimum_required(VERSION 3.10)
project(blockchain-cpp)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenSSL REQUIRED)

include_directories(${OPENSSL_INCLUDE_DIR})
include_directories(core)
include_directories(core/simulation)

add_executable(blockchain
    main.cpp
    core/src/block.cpp
    core/src/transaction.cpp
    core/simulation/simulation.cpp
)

add_executable(simulation
    main.cpp
    core/src/block.cpp
    core/src/transaction.cpp
    core/simulation/simulation.cpp
)

target_link_libraries(blockchain ${OPENSSL_LIBRARIES})
target_link_libraries(simulation ${OPENSSL_LIBRARIES})
