#pragma once
#include <string>
#include <stack>
#include "figure_factory.h"

class StreamFigureFactory : public FigureFactory
{
public:
    StreamFigureFactory(std::istream& stream);
    std::shared_ptr<Shape> create() override;
private:
    std::istream& m_figure_stream;
};