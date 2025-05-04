#pragma once
#include <string>

class Shape
{
public:
    virtual float CalcPerimeter()const = 0;
    virtual std::string GetStringRepresentation()const = 0;
    virtual ~Shape() = default;
};