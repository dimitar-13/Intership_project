#include "FigureFactory.h"
#include"Core/StringHelper.h"

Shape* FigureFactory::CreateShape(const std::string& figure_string)
{
    auto StringToLower = [](std::string& string)
        {
            for (auto& character : string)
                character = tolower(character);
        };

    Shape* result = nullptr;
    size_t parameter_start_loc = figure_string.find_first_of(' ') + 1;

    std::string figure_name = figure_string.substr(0, figure_string.find_first_of(' '));
    StringToLower(figure_name);

    if (parameter_start_loc >= figure_string.size())
        return result;

    std::string shape_parameter_string = figure_string.substr(parameter_start_loc,figure_string.size());

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

Shape* FigureFactory::CreateRandomShape()
{
    constexpr const size_t k_figure_type_size = 3;
    constexpr const char* k_figure_types[k_figure_type_size] = {
        "triangle","circle","rectangle"
    };

    auto GetRandomFloat = []()
        {
            return (double)(rand()) / (double)(RAND_MAX);
        };


    Shape* result = nullptr;

    size_t current_figure_type_index = rand() % k_figure_type_size;

    if (std::strcmp(k_figure_types[current_figure_type_index],"triangle") == 0)
    {
        float a = abs(GetRandomFloat()), b = abs(GetRandomFloat()), c = abs(GetRandomFloat());
        result = new Triangle(a, b, c);
    }
    else if (std::strcmp(k_figure_types[current_figure_type_index],"circle") == 0)
    {
        float r = abs(GetRandomFloat());
        result = new Circle(r);
    }
    else if (std::strcmp(k_figure_types[current_figure_type_index],"rectangle") == 0)
    {
        float a = abs(GetRandomFloat()), b = abs(GetRandomFloat());
        result = new Rectangle(a,b);
    }

    return result;
}


Shape* FigureFactory::CreateTriangle(const std::string& parameter_string)
{
    std::vector<double>tri_params = StringHelper::ExtractParametersFromString(parameter_string, ' ');

    if (tri_params.size() != 3)
        return nullptr;

    if (tri_params[0] <= 0 || tri_params[1] <= 0 || tri_params[2] <= 0)
        return nullptr;

    return new Triangle(tri_params[0], tri_params[1], tri_params[2]);
}

Shape* FigureFactory::CreateCircle(const std::string& parameter_string)
{
    std::vector<double>circle_param = StringHelper::ExtractParametersFromString(parameter_string, ' ');

    if (circle_param.size() != 1)
        return nullptr;

    if (circle_param[0] <= 0)
        return nullptr;

    return new Circle(circle_param[0]);
}

Shape* FigureFactory::CreateRectangle(const std::string& parameter_string)
{
    std::vector<double>rectangle_param = StringHelper::ExtractParametersFromString(parameter_string, ' ');

    if (rectangle_param.size() != 2)
        return nullptr;

    if (rectangle_param[0] <= 0)
        return nullptr;

    return new Rectangle(rectangle_param[0], rectangle_param[1]);
}
