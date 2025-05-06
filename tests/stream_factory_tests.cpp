#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_approx.hpp>
#include<sstream>

#include "figures/stream_figure_factory.h"


TEST_CASE("Stream factory empty stream test", "[factory]")
{
    std::istringstream empty_stream{ "" };

    StreamFigureFactory stream_factory(empty_stream);

    REQUIRE(stream_factory.create() == nullptr);
}
