#include "circle.h"

constexpr double k_PI = 3.14159265359;
constexpr double k_double_PI = 2.0f * k_PI;

Circle::Circle(float radius):
    m_radius(radius)
{
}

float Circle::CalcPerimeter() const
{
    return k_double_PI * m_radius;
}

std::string Circle::GetStringRepresentation() const
{
    return "circle " + std::to_string(m_radius);
}

Prototype* Circle::Clone()
{
    return new Circle(m_radius);
}
