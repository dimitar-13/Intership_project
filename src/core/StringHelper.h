#pragma once
#include<string>
#include<vector>
#include <memory>
#include "figures/figures.h"

class StringHelper
{
public:
    static std::shared_ptr<Shape> StringToShape(const std::string& figure_string);
    static std::vector<double> ExtractParametersFromString(const std::string& parameter_string, char seporator_symbol);
    static void StringToLower(std::string& string);
};