#include "StringHelper.h"

std::shared_ptr<Shape> StringHelper::StringToShape(const std::string& figure_string)
    {
        std::string figure_name;
        std::shared_ptr<Shape> result = nullptr;
        size_t parameter_start_loc;

        parameter_start_loc = figure_string.find_first_of(' ') + 1;

        figure_name = figure_string.substr(0, figure_string.find_first_of(' '));
        StringToLower(figure_name);

        if (parameter_start_loc >= figure_string.size())
            return result;

        std::string shape_parameter_string = figure_string.substr(parameter_start_loc, figure_string.size());

        if (figure_name == "triangle")
        {
            std::vector<double>tri_params = StringHelper::ExtractParametersFromString(shape_parameter_string, ' ');

            if (tri_params.size() != 3)
                return nullptr;

            if (tri_params[0] <= 0 || tri_params[1] <= 0 || tri_params[2] <= 0)
                return nullptr;

            result = std::make_shared<Triangle>(tri_params[0], tri_params[1], tri_params[2]);
        }
        else if (figure_name == "circle")
        {
            std::vector<double>circle_param = StringHelper::ExtractParametersFromString(shape_parameter_string, ' ');

            if (circle_param.size() != 1)
                return nullptr;

            if (circle_param[0] <= 0)
                return nullptr;

            result = std::make_shared<Circle>(circle_param[0]);
        }
        else if (figure_name == "rectangle")
        {
            std::vector<double>rectangle_param = StringHelper::ExtractParametersFromString(shape_parameter_string, ' ');

            if (rectangle_param.size() != 2)
                return nullptr;

            if (rectangle_param[0] <= 0)
                return nullptr;

            result = std::make_shared<Rectangle>(rectangle_param[0], rectangle_param[1]);
        }

        return result;
    }

std::vector<double> StringHelper::ExtractParametersFromString(const std::string& parameter_string,char seporator_symbol)
    {
        std::vector<double> result;
        std::string str_number;
        str_number.reserve(10);

        for (size_t i = 0; i < parameter_string.size(); i++)
        {
            if (parameter_string[i] == seporator_symbol)
            {
                if (!str_number.empty())
                {
                    result.push_back(stod(str_number));
                    str_number.clear();
                }
                continue;
            }
            str_number += parameter_string[i];
        }

        if(!str_number.empty())
            result.push_back(stod(str_number));

        return result;
    }
void StringHelper::StringToLower(std::string& string)
    {
        for (auto& character : string)
            character = tolower(character);
    }