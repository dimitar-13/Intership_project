#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_approx.hpp>

#include "core/StringHelper.h"


TEST_CASE("Figure factory case sensitive test", "[string_helper]")
{
    std::shared_ptr<Shape> triangle = StringHelper::StringToShape("TrIaNgle 10 3.42 5.32");

    REQUIRE(triangle != nullptr);
}

TEST_CASE("Figure factory case negative parameters", "[string_helper]")
{
    std::shared_ptr<Shape> triangle = StringHelper::StringToShape("triangle -10 3.42 5.32");

    REQUIRE(triangle == nullptr);
}

TEST_CASE("Figure factory case not enough parameters", "[string_helper]")
{
    std::shared_ptr<Shape> triangle = StringHelper::StringToShape("triangle 10 3.42");

    REQUIRE(triangle == nullptr);
}


TEST_CASE("Edge case no values.", "[string_extract]")
{
    std::vector<double> values = StringHelper::ExtractParametersFromString("", ' ');

    REQUIRE(values.size() == 0);
}

TEST_CASE("Edge case 1 value no seporator.", "[string_extract]")
{
    std::vector<double> values = StringHelper::ExtractParametersFromString("11.0", ' ');

    REQUIRE(values.size() == 1);

    REQUIRE(values[0] == 11.0);
}

TEST_CASE("Edge case tailing seporator.", "[string_extract]")
{
    std::vector<double> values = StringHelper::ExtractParametersFromString("11.0 12.0 ", ' ');

    REQUIRE(values.size() == 2);

    REQUIRE(values[0] == 11.0);

    REQUIRE(values[1] == 12.0);
}

TEST_CASE("Edge case front seporator.", "[string_extract]")
{
    std::vector<double> values = StringHelper::ExtractParametersFromString(" 11.0 12.0", ' ');

    REQUIRE(values.size() == 2);

    REQUIRE(values[0] == 11.0);

    REQUIRE(values[1] == 12.0);

}

TEST_CASE("Extract paramter string precision test", "[string_extract]")
{
    std::vector<double> values =
        StringHelper::ExtractParametersFromString("10.234214562334 3.42343653677343 5.3232325252562212", ' ');

    REQUIRE(values.size() == 3);

    REQUIRE(values[0] == 10.234214562334);

    REQUIRE(values[1] == 3.42343653677343);

    REQUIRE(values[2] == 5.3232325252562212);
}
