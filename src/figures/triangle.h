#include<figures/shape.h>

class Triangle : public Shape
{
public:
    Triangle(float a,float b,float c);
private:
    float CalcPerimeter() const override;
    std::string GetStringRepresentation() const override;
private:
    float m_side_a, m_side_b, m_side_c;
};