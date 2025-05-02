#pragma once
#include<figures/shape.h>
#include "core/Prototype.h"

class Triangle : public Shape, public Prototype
{
public:
    Triangle(float a,float b,float c);
private:
    float CalcPerimeter() const override;
    std::string GetStringRepresentation() const override;
    Prototype* Clone() override;
private:
    float m_side_a, m_side_b, m_side_c;
};