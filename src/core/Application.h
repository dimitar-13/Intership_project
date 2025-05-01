#pragma once
#include <vector>
#include "figures/shape.h"
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
    std::vector<Shape*> m_user_figure_list;
};