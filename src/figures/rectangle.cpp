#include "rectangle.h"

Rectangle::Rectangle(float a, float b):
    m_side_a(a),m_side_b(b)
{
}

float Rectangle::CalcPerimeter() const
{
    return 2*m_side_a + 2*m_side_b;
}

std::string Rectangle::GetStringRepresentation() const
{
    return "rectangle " + std::to_string(m_side_a) + ' ' + std::to_string(m_side_b);
}

std::shared_ptr<Prototype> Rectangle::Clone()
{
    return std::make_shared<Rectangle>(m_side_a,m_side_b);
}
