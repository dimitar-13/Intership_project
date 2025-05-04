#include "FileHelper.h"
#include <iostream>

bool FileHelper::WriteToFile(const char* file_path, const std::vector<std::string>& file_info)
{
    std::ofstream file_stream(file_path);
    
    if (!file_stream.is_open())
    {
        std::cout << "Failed to open file: " << file_path << '\n';
        return false;
    }

    for (const std::string& shape : file_info)
    {
        file_stream << shape << '\n';
    }

    file_stream.close();

    return true;
}

bool FileHelper::ReadFromFile(const char* file_path, std::vector<std::string>& file_read_output)
{
    std::ifstream file_stream(file_path);

    if (!file_stream.is_open())
    {
        std::cout << "Failed to open file: " << file_path << '\n';
        return false;
    }

    std::string str;
    while (std::getline(file_stream, str))
    {
        file_read_output.emplace_back(std::move(str));
    }

    file_stream.close();

    return true;
}
