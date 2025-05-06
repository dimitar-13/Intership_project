#pragma once
#include "figure_factory.h"

class RandomFigureFactory : public FigureFactory
{
public:
    RandomFigureFactory();

    std::shared_ptr<Shape> create() override;
};