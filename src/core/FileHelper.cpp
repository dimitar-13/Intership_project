#include "FileHelper.h"
#include <iostream>

bool FileHelper::WriteToFile(const std::string& file_path, const std::vector<std::string>& file_info)
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
