#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>

#include "money.h"

#include <sstream>

using namespace std;

TEST_CASE("Parse dollar amount")
{
    REQUIRE(Money("$0.00").getCents() == 0);
    REQUIRE(Money("$123.45").getCents() == 12345);
}

TEST_CASE("Output string")
{
    ostringstream ss;
    ss << Money(12345);
    REQUIRE(ss.str() == "$123.45");
}

TEST_CASE("Less than operator")
{
    REQUIRE(Money(3) < Money(4));
    REQUIRE_FALSE(Money(4) < Money(3));
    REQUIRE_FALSE(Money(3) < Money(3));
}

TEST_CASE("Greater than operator")
{
    REQUIRE(Money(4) > Money(3));
    REQUIRE_FALSE(Money(3) > Money(4));
    REQUIRE_FALSE(Money(3) > Money(3));
}

TEST_CASE("Equal to operator")
{
    REQUIRE(Money(3) == Money(3));
    REQUIRE_FALSE(Money(3) == Money(4));
    REQUIRE_FALSE(Money(4) == Money(3));
}

TEST_CASE("Add to operator")
{
    Money money(0);
    REQUIRE(money.getCents() == 0);
    money += Money(42);
    REQUIRE(money.getCents() == 42);
    money += Money(100);
    REQUIRE(money.getCents() == 142);
}
