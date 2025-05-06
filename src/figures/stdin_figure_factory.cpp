#include "stdin_figure_factory.h"
#include "Core/StringHelper.h"
#include <iostream>
#include <string>


std::shared_ptr<Shape> InputFigureFactory::CreateTriangle(const std::string& parameter_string)
{
    std::vector<double>tri_params = StringHelper::ExtractParametersFromString(parameter_string, ' ');

    if (tri_params.size() != 3)
        return nullptr;

    if (tri_params[0] <= 0 || tri_params[1] <= 0 || tri_params[2] <= 0)
        return nullptr;

    return std::make_shared<Triangle>(tri_params[0], tri_params[1], tri_params[2]);
}

std::shared_ptr<Shape> InputFigureFactory::CreateCircle(const std::string& parameter_string)
{
    std::vector<double>circle_param = StringHelper::ExtractParametersFromString(parameter_string, ' ');

    if (circle_param.size() != 1)
        return nullptr;

    if (circle_param[0] <= 0)
        return nullptr;

    return std::make_shared<Circle>(circle_param[0]);
}

std::shared_ptr<Shape> InputFigureFactory::CreateRectangle(const std::string& parameter_string)
{
    std::vector<double>rectangle_param = StringHelper::ExtractParametersFromString(parameter_string, ' ');

    if (rectangle_param.size() != 2)
        return nullptr;

    if (rectangle_param[0] <= 0)
        return nullptr;

    return std::make_shared<Rectangle>(rectangle_param[0], rectangle_param[1]);
}

std::shared_ptr<Shape> InputFigureFactory::create()
{
    auto StringToLower = [](std::string& string)
        {
            for (auto& character : string)
                character = tolower(character);
        };

    std::string user_input_string, figure_name;
    std::shared_ptr<Shape> result = nullptr;
    size_t parameter_start_loc;

    std::cout << "Enter figure with following format: <figure_name> <parameters>" << '\n';
    getline(std::cin, user_input_string);

    parameter_start_loc = user_input_string.find_first_of(' ') + 1;

    figure_name = user_input_string.substr(0, user_input_string.find_first_of(' '));
    StringToLower(figure_name);

    if (parameter_start_loc >= user_input_string.size())
        return result;

    std::string shape_parameter_string = user_input_string.substr(parameter_start_loc, user_input_string.size());

    if (figure_name == "triangle")
    {
        result = CreateTriangle(shape_parameter_string);
    }
    else if (figure_name == "circle")
    {
        result = CreateCircle(shape_parameter_string);
    }
    else if (figure_name == "rectangle")
    {
        result = CreateRectangle(shape_parameter_string);
    }

    return result;
}
