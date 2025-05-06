#pragma once
#include "figure_factory.h"
#include <stack>

class RandomFigureFactory : public FigureFactory
{
public:
    RandomFigureFactory(size_t max_count);

    std::shared_ptr<Shape> create() override;
private:
    std::shared_ptr<Shape> CreateRandomShape();
private:
    std::stack<std::shared_ptr<Shape>> m_factory_figure_stack;
};