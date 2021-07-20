#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <catch2/catch.hpp>

#include <cregexp.h>

TEST_CASE("Basic tests", "[testBasic]")
{
    REQUIRE(true  == cregexp::match(nullptr, "Some"));
    REQUIRE(true  == cregexp::match("", ""));
    REQUIRE(true  == cregexp::match("", "Some"));
    REQUIRE(true  == cregexp::match("*", ""));
    REQUIRE(false == cregexp::match("?", ""));
    REQUIRE(true  == cregexp::match("?", "A"));

    REQUIRE(true  == cregexp::match("Some", "Some"));
    REQUIRE(false == cregexp::match("Some", "FooSome"));
    REQUIRE(false == cregexp::match("Some", "SomeBar"));
    REQUIRE(false == cregexp::match("Some", "FooSomeBar"));
    REQUIRE(false == cregexp::match("Some", "FooBar"));
}

TEST_CASE("Zero or more token test", "[testZeroOrMore]")
{
    REQUIRE(true  == cregexp::match("*Some", "Some"));
    REQUIRE(true  == cregexp::match("*Some", "FooSome"));
    REQUIRE(false == cregexp::match("*Some", "SomeBar"));
    REQUIRE(false == cregexp::match("*Some", "FooSomeBar"));
    REQUIRE(false == cregexp::match("*Some", "FooBar"));

    REQUIRE(true  == cregexp::match("Some*", "Some"));
    REQUIRE(false == cregexp::match("Some*", "FooSome"));
    REQUIRE(true  == cregexp::match("Some*", "SomeBar"));
    REQUIRE(false == cregexp::match("Some*", "FooSomeBar"));
    REQUIRE(false == cregexp::match("Some*", "FooBar"));

    REQUIRE(true  == cregexp::match("*Some*", "Some"));
    REQUIRE(true  == cregexp::match("*Some*", "FooSome"));
    REQUIRE(true  == cregexp::match("*Some*", "SomeBar"));
    REQUIRE(true  == cregexp::match("*Some*", "FooSomeBar"));
    REQUIRE(false == cregexp::match("*Some*", "FooBar"));

    REQUIRE(true  == cregexp::match("*So*me*", "Some"));
    REQUIRE(true  == cregexp::match("*So*me*", "FooSome"));
    REQUIRE(true  == cregexp::match("*So*me*", "SomeBar"));
    REQUIRE(true  == cregexp::match("*So*me*", "FooSomeBar"));
    REQUIRE(false == cregexp::match("*So*me*", "FooBar"));
    REQUIRE(true  == cregexp::match("*So*me*", "FooSoBarKmeBar"));

    REQUIRE(true  == cregexp::match("*****Some***", "Some"));
    REQUIRE(true  == cregexp::match("*****Some***", "FooSome"));
    REQUIRE(true  == cregexp::match("*****Some***", "SomeBar"));
    REQUIRE(true  == cregexp::match("*****Some***", "FooSomeBar"));
    REQUIRE(false == cregexp::match("*****Some***", "FooBar"));
}

TEST_CASE("Test CRegExp", "[testExactlyOne]")
{
    REQUIRE(false == cregexp::match("?Some", "Some"));
    REQUIRE(false == cregexp::match("?Some", "FooSome"));
    REQUIRE(false == cregexp::match("?Some", "SomeBar"));
    REQUIRE(false == cregexp::match("?Some", "FooSomeBar"));
    REQUIRE(false == cregexp::match("?Some", "FooBar"));
    REQUIRE(true  == cregexp::match("?Some", "FSome"));
    REQUIRE(false == cregexp::match("?Some", "FSomeB"));

    REQUIRE(false == cregexp::match("Some?", "Some"));
    REQUIRE(false == cregexp::match("Some?", "FooSome"));
    REQUIRE(false == cregexp::match("Some?", "SomeBar"));
    REQUIRE(false == cregexp::match("Some?", "FooSomeBar"));
    REQUIRE(false == cregexp::match("Some?", "FooBar"));
    REQUIRE(false == cregexp::match("Some?", "FSome"));
    REQUIRE(true  == cregexp::match("Some?", "SomeB"));
    REQUIRE(false == cregexp::match("Some?", "FSomeB"));

    REQUIRE(false == cregexp::match("?Some?", "Some"));
    REQUIRE(false == cregexp::match("?Some?", "FooSome"));
    REQUIRE(false == cregexp::match("?Some?", "SomeBar"));
    REQUIRE(false == cregexp::match("?Some?", "FooSomeBar"));
    REQUIRE(false == cregexp::match("?Some?", "FooBar"));
    REQUIRE(false == cregexp::match("?Some?", "FSome"));
    REQUIRE(false == cregexp::match("?Some?", "SomeB"));
    REQUIRE(true  == cregexp::match("?Some?", "FSomeB"));
}

TEST_CASE("Combined tests", "[testCombined]")
{
    REQUIRE(false == cregexp::match("So*?me", "Some"));
    REQUIRE(true  == cregexp::match("So*?me", "SoBarKme"));
    REQUIRE(true  == cregexp::match("So*?me", "SoBKme"));
}
