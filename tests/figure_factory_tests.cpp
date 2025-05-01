#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_approx.hpp>

#include "figures/FigureFactory.h"

TEST_CASE("Figure factory basic shape creating test", "[figure_factory_test]")
{
    Shape* triangle = FigureFactory::CreateShape("triangle 10 3.42 5.32");
    Shape* circle = FigureFactory::CreateShape("circle 10");
    Shape* rectangle = FigureFactory::CreateShape("rectangle 10 3.42");

    REQUIRE(triangle->CalcPerimeter() == Catch::Approx(10.0 + 3.42 + 5.32).epsilon(0.0001f));
    REQUIRE(circle->CalcPerimeter() == Catch::Approx(2.0 * 3.14159265359 * 10.0).epsilon(0.0001f));
    REQUIRE(rectangle->CalcPerimeter() == Catch::Approx(2.0 * 10.0 + 2.0 * 3.42).epsilon(0.0001f));

    delete triangle;
    delete circle;
    delete rectangle;
}

TEST_CASE("Figure factory case sensitive test", "[figure_factory_test]")
{
    Shape* triangle = FigureFactory::CreateShape("TrIaNgle 10 3.42 5.32");

    REQUIRE(triangle != nullptr);

    delete triangle;
}

TEST_CASE("Figure factory case negative parameters", "[figure_factory_test]")
{
    Shape* triangle = FigureFactory::CreateShape("triangle -10 3.42 5.32");

    REQUIRE(triangle == nullptr);

    delete triangle;
}

TEST_CASE("Figure factory case not enough parameters", "[figure_factory_test]")
{
    Shape* triangle = FigureFactory::CreateShape("triangle 10 3.42");
    Shape* circle = FigureFactory::CreateShape("circle ");
    Shape* rectangle = FigureFactory::CreateShape("rectangle 10");

    REQUIRE(triangle == nullptr);
    REQUIRE(circle == nullptr);
    REQUIRE(rectangle == nullptr);

    delete triangle;
    delete circle;
    delete rectangle;
}
