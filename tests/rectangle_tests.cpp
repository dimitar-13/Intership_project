#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_approx.hpp>
#include "figures/rectangle.h"

TEST_CASE("Rectangle parameter precision test", "")
{
    Shape* rectangle = new Rectangle(2.24343423232,4.34545454546565654);

    REQUIRE(rectangle->CalcPerimeter() == Catch::Approx(13.17778).epsilon(0.0001f));

    delete rectangle;
}