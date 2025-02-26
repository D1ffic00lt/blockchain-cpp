cmake_minimum_required(VERSION 3.29)
project(blockchain)

set(CMAKE_CXX_STANDARD 20)

add_executable(blockchain main.cpp
        core/transaction.h
        core/transaction.cpp
        core/block.h
        core/block.cpp)
