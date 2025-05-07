#include <iostream>
#include "Application.h"
#include "FileHelper.h"
#include "StringHelper.h"

#include <figures/shape_input_factory.h>


Application::Application()
{
    RunProgram();
}

Application::~Application()
{
}

void Application::RunProgram()
{
    CreateFigureList();
    EditFigureList();
}


void Application::CreateFigureList()
{
    std::string choice;
    std::unique_ptr<FigureFactory> factory = nullptr;
    while (true)
    {
        std::cout << "1)Random (creates random figure list)"   << '\n'
                  << "2)Input  (input a figure list)"           << '\n'
                  << "3)File   (creates figure list from file)" << '\n';
 
        std::cin >> choice;
        
        ShapeInputFactory abs_factory(choice);
        factory = abs_factory.createFactory();

        if (factory != nullptr)
            break;
    }

    while (true)
    {
        std::shared_ptr<Shape> retrieved_shape = factory->create();

        if (retrieved_shape == nullptr)
            break;

        m_user_figure_list.push_back(retrieved_shape);
    }

}

void Application::EditFigureList()
{
    int option = 0;

    while (true)
    {
        std::cout << "1) Display all figures"   << '\n'
                  << "2) Remove figure"         << '\n'
                  << "3) Duplicate figure"      << '\n'
                  << "4) Store figures to file" << '\n'
                  << "5) Exit"                  << '\n';

        std::cin >> option;
        switch (option)
        {
        case 1:
            ListFigures();
            break;
        case 2:
            RemoveFigure();
            break;
        case 3:
            DuplicateAndAppendToEnd();
            break;
        case 4:
            StoreBackToFile();
            break;
        case 5:
            return;
            break;
        default:
            std::cout << "Enter a valid option" << '\n';
            break;
        }
    }
}

void Application::ListFigures()
{
    for (std::shared_ptr<Shape> figure : m_user_figure_list)
        std::cout << figure->GetStringRepresentation() << '\n';
}

void Application::RemoveFigure()
{
    size_t selected_figure_number = 0,selected_figure_index = 0;

    ListFigures();
    std::cout << "Enter the of figure you want to delete(1,2,3 etc.)" << '\n';

    std::cin >> selected_figure_number;

    if (selected_figure_number > m_user_figure_list.size())
    {
        std::cout << "Figure does not exist" << '\n';
        return;
    }
    selected_figure_index = selected_figure_number - 1;

    m_user_figure_list.erase(m_user_figure_list.begin() + (selected_figure_index));
}

void Application::DuplicateAndAppendToEnd()
{
    size_t selected_figure_number = 0;

    ListFigures();
    std::cout << "Enter the of figure you want to copy(1,2,3 etc.)" << '\n';

    std::cin >> selected_figure_number;

    if (selected_figure_number > m_user_figure_list.size())
    {
        std::cout << "Figure does not exist" << '\n';
        return;
    }

    std::shared_ptr<Prototype> prototype_cast = std::dynamic_pointer_cast<Prototype>(m_user_figure_list[selected_figure_number - 1]);

    if (prototype_cast == nullptr)
    {
        std::cout << "Invalid figure type" << '\n';
        return;
    }

    m_user_figure_list.push_back(std::dynamic_pointer_cast<Shape>(prototype_cast->Clone()));
}

void Application::StoreBackToFile()
{
    std::vector<std::string> shape_string_data;
    shape_string_data.resize(m_user_figure_list.size());

    for (size_t i = 0; i < shape_string_data.size(); i++)
    {
        shape_string_data[i] = m_user_figure_list[i]->GetStringRepresentation();
    }
    std::string file_path;

    std::cout << "Enter file path" << '\n';
    std::cin >> file_path;

    FileHelper::WriteToFile(file_path, shape_string_data);
}
