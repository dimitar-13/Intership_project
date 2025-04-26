#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_approx.hpp>
#include "figures/circle.h"

TEST_CASE("Circle parameter presision test", "")
{
    Shape* circle = new Circle(2.2);
   
    REQUIRE(circle->CalcPerimeter() == Catch::Approx(13.82301f).epsilon(0.0001f));

    delete circle;
}