#pragma once
#include "figures/shape.h"
#include "core/Prototype.h"

class Circle : public Shape, public Prototype
{
public:
    Circle(float radius);
private:
    float CalcPerimeter() const override;
    std::string GetStringRepresentation() const override;
    std::shared_ptr<Prototype> Clone() override;
private:
    float m_radius;
};