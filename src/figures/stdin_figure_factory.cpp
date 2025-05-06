#include "stdin_figure_factory.h"
#include "Core/StringHelper.h"
#include <iostream>
#include <string>

std::shared_ptr<Shape> InputFigureFactory::create()
{
    std::string user_input_string, figure_name;
    std::shared_ptr<Shape> result = nullptr;
    size_t parameter_start_loc;

    std::cout << "Enter figure with following format: <figure_name> <parameters>" << '\n';
    getline(std::cin, user_input_string);

   
    return StringHelper::StringToShape(user_input_string);
}
