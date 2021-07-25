cmake_minimum_required(VERSION 3.17)

project(CRegExpTests)

include_directories(../include)

set(test_sources catch.hpp test.cpp)
add_executable(CRegExpTests ${test_sources})
target_link_libraries(CRegExpTests CRegExp)

add_test(NAME CRegExpTests COMMAND CRegExpTests)