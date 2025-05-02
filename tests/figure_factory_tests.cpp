#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_approx.hpp>

#include "figures/FigureFactory.h"

TEST_CASE("Figure factory basic shape creating test", "[figure_factory_test]")
{
    std::shared_ptr<Shape> triangle = FigureFactory::CreateShape("triangle 10 3.42 5.32");
    std::shared_ptr<Shape> circle = FigureFactory::CreateShape("circle 10");
    std::shared_ptr<Shape> rectangle = FigureFactory::CreateShape("rectangle 10 3.42");

    REQUIRE(triangle->CalcPerimeter() == Catch::Approx(10.0 + 3.42 + 5.32).epsilon(0.0001f));
    REQUIRE(circle->CalcPerimeter() == Catch::Approx(2.0 * 3.14159265359 * 10.0).epsilon(0.0001f));
    REQUIRE(rectangle->CalcPerimeter() == Catch::Approx(2.0 * 10.0 + 2.0 * 3.42).epsilon(0.0001f));
}

TEST_CASE("Figure factory case sensitive test", "[figure_factory_test]")
{
    std::shared_ptr<Shape> triangle = FigureFactory::CreateShape("TrIaNgle 10 3.42 5.32");

    REQUIRE(triangle != nullptr);
}

TEST_CASE("Figure factory case negative parameters", "[figure_factory_test]")
{
    std::shared_ptr<Shape> triangle = FigureFactory::CreateShape("triangle -10 3.42 5.32");

    REQUIRE(triangle == nullptr);
}

TEST_CASE("Figure factory case not enough parameters", "[figure_factory_test]")
{
    std::shared_ptr<Shape> triangle = FigureFactory::CreateShape("triangle 10 3.42");
    std::shared_ptr<Shape> circle = FigureFactory::CreateShape("circle ");
    std::shared_ptr<Shape> rectangle = FigureFactory::CreateShape("rectangle 10");

    REQUIRE(triangle == nullptr);
    REQUIRE(circle == nullptr);
    REQUIRE(rectangle == nullptr);

}
