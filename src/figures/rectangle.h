#pragma once
#include "figures/shape.h"
#include "core/Prototype.h"

class Rectangle : public Shape , public Prototype
{
public:
    Rectangle(float a, float b);
private:
    float CalcPerimeter() const override;
    std::string GetStringRepresentation() const override;
    std::shared_ptr<Prototype> Clone() override;
private:
    float m_side_a, m_side_b;
};