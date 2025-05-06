#pragma once
#include <string>
#include "figure_factory.h"

class InputFigureFactory : public FigureFactory
{
public:
    std::shared_ptr<Shape> create() override;
};