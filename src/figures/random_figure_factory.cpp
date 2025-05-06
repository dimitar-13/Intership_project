#include "random_figure_factory.h"
#include<iostream>

RandomFigureFactory::RandomFigureFactory(size_t max_count)
{
    srand(time(0));
    size_t figure_count = rand() % max_count;

    for (size_t i = 0; i < figure_count; i++)
    {
        m_factory_figure_stack.push(CreateRandomShape());
    }
}

std::shared_ptr<Shape> RandomFigureFactory::create()
{
    std::shared_ptr<Shape> result = nullptr;

    if (m_factory_figure_stack.empty())
        return result;

    result = m_factory_figure_stack.top();
    m_factory_figure_stack.pop();

    return result;
}

std::shared_ptr<Shape> RandomFigureFactory::CreateRandomShape()
{
    constexpr const size_t k_figure_type_size = 3;
    constexpr const char* k_figure_types[k_figure_type_size] = {
        "triangle","circle","rectangle"
    };

    auto GetRandomFloat = []()
        {
            return (double)(rand()) / (double)(RAND_MAX);
        };


    std::shared_ptr<Shape> result = nullptr;

    size_t current_figure_type_index = rand() % k_figure_type_size;

    if (std::strcmp(k_figure_types[current_figure_type_index], "triangle") == 0)
    {
        float a = abs(GetRandomFloat()), b = abs(GetRandomFloat()), c = abs(GetRandomFloat());
        result = std::make_shared<Triangle>(a, b, c);
    }
    else if (std::strcmp(k_figure_types[current_figure_type_index], "circle") == 0)
    {
        float r = abs(GetRandomFloat());
        result = std::make_shared<Circle>(r);
    }
    else if (std::strcmp(k_figure_types[current_figure_type_index], "rectangle") == 0)
    {
        float a = abs(GetRandomFloat()), b = abs(GetRandomFloat());
        result = std::make_shared<Rectangle>(a, b);
    }

    return result;
}
