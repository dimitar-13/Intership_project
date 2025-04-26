#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_approx.hpp>
#include "figures/triangle.h"

TEST_CASE("Triangle parameter precision test", "")
{
    Shape* triangle = new Triangle(2.24565f, 3.4235353f, 2.4344343f);

    REQUIRE(triangle->CalcPerimeter() == Catch::Approx(8.1036196f).epsilon(0.0001f));

    delete triangle;
}