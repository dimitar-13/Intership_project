#include "figures/shape.h"
#include <vector>

class Application
{
public:
    Application();
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
private:
    std::vector<Shape*> m_user_figure_list;
};