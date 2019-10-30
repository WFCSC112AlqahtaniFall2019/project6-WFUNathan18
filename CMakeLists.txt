cmake_minimum_required(VERSION 3.14.5)
project(BinaryInsertionSort)

set(CMAKE_CXX_STANDARD 11)

add_executable(BinaryInsertionSort InsertionSort.cpp BinaryInsertionSort.cpp LinkedList.h LinkedList.cpp)