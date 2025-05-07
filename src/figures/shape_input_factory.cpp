#include "shape_input_factory.h"
#include "core/StringHelper.h"
#include "stream_figure_factory.h"
#include "random_figure_factory.h"
#include <sstream>
#include <iostream>
#include <fstream>

ShapeInputFactory::ShapeInputFactory(const std::string& input_type)
{
    m_input_type_string = input_type;

    StringHelper::StringToLower(m_input_type_string);

}

std::unique_ptr<FigureFactory> ShapeInputFactory::createFactory()
{
    std::unique_ptr<FigureFactory> result = nullptr;

    if (m_input_type_string.compare("file") == 0 )
    {
        std::string file_path;

        std::cout << "Enter file path" << '\n';
        std::cin >> file_path;

        std::fstream file(file_path);

        if (file.is_open())
        {
            result = std::make_unique<StreamFigureFactory>(file);
        }    
    }
    else if (m_input_type_string.compare("input") == 0)
    {
        std::stringstream figure_input_stream;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        while (true) {
            std::string line;
            std::cout << "Press enter to stop" << '\n';
            std::cout << "Figure enter format: <figure name> <parameters...>" << '\n';
            std::getline(std::cin, line);
            if (line.empty())
                break;

            figure_input_stream << line << '\n';
        }
        result = std::make_unique<StreamFigureFactory>(figure_input_stream);
    }
    else if (m_input_type_string.compare("random") == 0)
    {
        int min = 0 , max = 10;

        std::cout << "Enter random range:min";
        std::cin >> min;

        std::cout << "Enter random range:max";
        std::cin >> max;

        result = std::make_unique<RandomFigureFactory>(min,max);
    }

    return result;
}
