#pragma once
#include "abstract_factory.h"

class ShapeInputFactory : public AbstractFactory
{
public:
    ShapeInputFactory(const std::string& input_type);
    std::unique_ptr<FigureFactory> createFactory() override;
private:
    std::string m_input_type_string;
};