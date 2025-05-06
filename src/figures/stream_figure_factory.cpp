#include "stream_figure_factory.h"
#include "Core/StringHelper.h"
#include <iostream>
#include <string>
#include <fstream>


StreamFigureFactory::StreamFigureFactory(std::istream& stream):
    m_figure_stream(stream)
{
}

std::shared_ptr<Shape> StreamFigureFactory::create()
{
    std::string stream_string;
    std::shared_ptr<Shape> result = nullptr;

    if (m_figure_stream.eof())
        return result;

    getline(m_figure_stream, stream_string);

    return StringHelper::StringToShape(stream_string);
}
