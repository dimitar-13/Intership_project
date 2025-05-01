#pragma once
#include "figures/shape.h"

class Circle : public Shape
{
public:
    Circle(float radius);
private:
    float CalcPerimeter() const override;
    std::string GetStringRepresentation() const override;
private:
    float m_radius;
};