#pragma once
#include "figure_factory.h"

class AbstractFactory
{
public:
    virtual ~AbstractFactory() = default;
    virtual std::unique_ptr<FigureFactory> createFactory() = 0;
};