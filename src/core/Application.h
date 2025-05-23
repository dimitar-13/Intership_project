#pragma once
#include <vector>
#include<memory>
#include "figures/shape.h"
#include "figures/random_figure_factory.h"
#include "figures/stream_figure_factory.h"

class Application
{
public:
    Application();
    ~Application();
private:
    void RunProgram();

    void CreateFigureList();
    
    void EditFigureList();
    void ListFigures();
    void RemoveFigure();
    void DuplicateAndAppendToEnd();
    void StoreBackToFile();

private:
    std::vector<std::shared_ptr<Shape>> m_user_figure_list;
};