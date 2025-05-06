#pragma once
#include <string>
#include "figure_factory.h"

class InputFigureFactory : public FigureFactory
{
public:
    std::shared_ptr<Shape> create() override;
private:
    static std::shared_ptr<Shape> CreateTriangle(const std::string& parameter_string);
    static std::shared_ptr<Shape> CreateCircle(const std::string& parameter_string);
    static std::shared_ptr<Shape> CreateRectangle(const std::string& parameter_string);
};