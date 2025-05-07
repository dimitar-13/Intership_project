#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_approx.hpp>
#include <sstream>

#include "figures/shape_input_factory.h"
#include "figures/stream_figure_factory.h"

TEST_CASE("Shape input factory invalid input test", "[factory]")
{
    ShapeInputFactory abstract_factory("unknown");

    std::unique_ptr<FigureFactory> factory = abstract_factory.createFactory();

    REQUIRE(factory == nullptr);
}

TEST_CASE("Shape valid input factory test", "[factory]")
{
    ShapeInputFactory abstract_factory("file");

    std::shared_ptr<FigureFactory> factory = abstract_factory.createFactory();
    std::shared_ptr<StreamFigureFactory> stream_factory = std::dynamic_pointer_cast<StreamFigureFactory>(factory);

    REQUIRE(factory != nullptr);
    REQUIRE(stream_factory != nullptr);
}
