#pragma once
#include "figure_factory.h"

class RandomFigureFactory : public FigureFactory
{
public:
    std::shared_ptr<Shape> create() override;
};