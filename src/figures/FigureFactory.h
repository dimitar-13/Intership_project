#pragma once
#include <string>
#include<memory>
#include "figures/triangle.h"
#include "figures/circle.h"
#include "figures/rectangle.h"

class FigureFactory
{
public:
    static std::shared_ptr<Shape> CreateShape(const std::string& figure_string);
    static std::shared_ptr<Shape> CreateRandomShape();
private:
    static std::shared_ptr<Shape> CreateTriangle(const std::string& parameter_string);
    static std::shared_ptr<Shape> CreateCircle(const std::string& parameter_string);
    static std::shared_ptr<Shape> CreateRectangle(const std::string& parameter_string);
};