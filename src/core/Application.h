#pragma once
#include <vector>
#include "figures/shape.h"
#include<memory>
class Application
{
public:
    Application();
    ~Application();
private:
    void RunProgram();

    void CreateFigureList();
    void CreateRandomFigure();
    void InputFigureString();
    void ReadFiguresFromFile();
    
    void EditFigureList();
    void ListFigures();
    void RemoveFigure();
    void DuplicateAndAppendToEnd();

    void ReleaseResources();
private:
    std::vector<std::shared_ptr<Shape>> m_user_figure_list;
};