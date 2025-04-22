#include "figures/shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(float a, float b);
private:
    float CalcPerimeter() const override;
    std::string GetStringRepresentation() const override;
private:
    float m_side_a, m_side_b;
};