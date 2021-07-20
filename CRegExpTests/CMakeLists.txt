cmake_minimum_required(VERSION 3.17)

project(CRegExpTests)

include_directories(include)
include_directories(../include)

set(test_sources ../cregexp.cpp test.cpp)
add_executable(CRegExpTests ${test_sources})

add_test(NAME CRegExpTests COMMAND CRegExpTests)