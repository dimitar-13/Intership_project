#include "triangle.h"

Triangle::Triangle(float a, float b, float c):
    m_side_a(a),m_side_b(b),m_side_c(c)
{
}

float Triangle::CalcPerimeter() const
{
    return m_side_a + m_side_b + m_side_c;
}


std::string Triangle::GetStringRepresentation() const
{
    return "triangle " + std::to_string(m_side_a) + ' ' + std::to_string(m_side_b) + ' ' + std::to_string(m_side_c);
}

std::shared_ptr<Prototype> Triangle::Clone()
{
    return std::make_shared<Triangle>(m_side_a,m_side_b,m_side_c);
}
