cmake_minimum_required(VERSION 3.19)
project(CRegExpTests)

set(CMAKE_CXX_STANDARD 11)

set(lib_sources include/cregexp.h cregexp.cpp)

add_library(CRegExp STATIC ${lib_sources})

enable_testing()
add_subdirectory(CRegExpTests tests)