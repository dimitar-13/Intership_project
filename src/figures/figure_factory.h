#pragma once
#include "Shape.h"
#include<memory>
#include "figures.h"

class FigureFactory
{
public:
    virtual std::shared_ptr<Shape> create() = 0;
    virtual ~FigureFactory() = default;
};