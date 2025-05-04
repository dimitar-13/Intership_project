#include <iostream>
#include "Application.h"
#include "figures/FigureFactory.h"
#include "FileHelper.h"

const char* k_Shape_save_file_location = "D:/c++/Intership/Intership_project/shape_file.txt";


Application::Application()
{
    RunProgram();
}

Application::~Application()
{
    ReleaseResources();
}

void Application::RunProgram()
{
    srand(time(0));

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
    size_t figure_count = rand() % 10;
    m_user_figure_list.reserve(figure_count);

    for (size_t i = 0; i < figure_count; i++)
    {
        m_user_figure_list.push_back(FigureFactory::CreateRandomShape());
    }
}

void Application::InputFigureString()
{
    size_t figure_count = 0;
    std::string figure_string;

    std::cout << "Enter how many figures u want to input" << '\n';
    std::cin >> figure_count;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    m_user_figure_list.reserve(figure_count);

    for (size_t i = 0; i < figure_count; i++)
    {
        std::cout << "Enter figure with following format: <figure_name> <parameters>" << '\n';
        getline(std::cin,figure_string);
        std::shared_ptr<Shape> figure = FigureFactory::CreateShape(figure_string);

        if (figure == nullptr)
        {
            i--;
            std::cout << "Failed to create valid figure! Please try again." << '\n';
            continue;
        }

        m_user_figure_list.push_back(figure);
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
                  << "4) Store figures to file" << '\n'
                  << "5) Exit"                << '\n';

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

    FileHelper::WriteToFile(k_Shape_save_file_location, shape_string_data);
}

void Application::ReleaseResources()
{
    m_user_figure_list.clear();
}
