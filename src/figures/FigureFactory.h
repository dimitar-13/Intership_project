#pragma once
#include <string>
#include "figures/triangle.h"
#include "figures/circle.h"
#include "figures/rectangle.h"

class FigureFactory
{
public:
    static Shape* CreateShape(const std::string& figure_string);

private:
    static Shape* CreateTriangle(const std::string& parameter_string);
    static Shape* CreateCircle(const std::string& parameter_string);
    static Shape* CreateRectangle(const std::string& parameter_string);
};