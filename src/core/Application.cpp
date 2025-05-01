#include "Application.h"
#include<iostream>



Application::Application()
{
    RunProgram();
}

void Application::RunProgram()
{
    CreateFigureList();
    EditFigureList();
}


void Application::CreateFigureList()
{
    int option = 0;

    while (true)
    {
        std::cout << "1)Create random figure list."   << '\n'
                  << "2)Input figure list."           << '\n'
                  << "3)Input figure list from file." << '\n';
 
        std::cin >> option;

            switch (option)
            {
            case 1: 
                CreateRandomFigure();
                return;
                break;
            case 2:
                InputFigureString();
                return;
                break;
            case 3:
                ReadFiguresFromFile();
                return;
                break;

            default:
                std::cout << "Invalid option." << '\n';
                break;
            }
    }

}

void Application::CreateRandomFigure()
{
}

void Application::InputFigureString()
{
    size_t figure_count = 0;
    std::string figure_string;

    std::cout << "Enter how many figures u want to input" << '\n';
    std::cin >> figure_count;

    m_user_figure_list.reserve(figure_count);

    for (size_t i = 0; i < figure_count; i++)
    {
        std::cin >> figure_string.data();

    }
}

void Application::ReadFiguresFromFile()
{
}


void Application::EditFigureList()
{
    int option = 0;

    while (true)
    {
        std::cout << "1) Display all figures" << '\n'
                  << "2) Remove figure"       << '\n'
                  << "3) Duplicate figure"    << '\n'
                  << "4) Exit"                << '\n';

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
}

void Application::RemoveFigure()
{
}

void Application::DuplicateAndAppendToEnd()
{
}
