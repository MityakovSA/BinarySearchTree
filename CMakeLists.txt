cmake_minimum_required(VERSION 3.6)
project(BinarySearchTree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES examples/main.cpp include/BinarySearchTree.h source/BinarySearchTree.cpp)
add_executable(BinarySearchTree ${SOURCE_FILES})

