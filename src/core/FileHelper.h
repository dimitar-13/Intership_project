#pragma once
#include<vector>
#include<string>
#include<fstream>

class FileHelper
{
public:
    static bool WriteToFile(const char* file_path,const std::vector<std::string>& file_info);
    static bool ReadFromFile(const char* file_path, std::vector<std::string>& file_read_output);
};

