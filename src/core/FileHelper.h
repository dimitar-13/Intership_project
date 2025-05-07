#pragma once
#include<vector>
#include<string>
#include<fstream>

class FileHelper
{
public:
    static bool WriteToFile(const std::string& file_path,const std::vector<std::string>& file_info);
};

