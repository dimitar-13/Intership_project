#include<string>
#include<vector>

class StringHelper
{
public:
    static std::vector<double> ExtractParametersFromString(
        const std::string& parameter_string,char seporator_symbol)
    {
        std::vector<double> result;
        std::string str_number;
        str_number.reserve(10);

        for (size_t i = 0; i < parameter_string.size(); i++)
        {
            if (parameter_string[i] == seporator_symbol)
            {
                if (!str_number.empty())
                {
                    result.push_back(stod(str_number));
                    str_number.clear();
                }
                continue;
            }
            str_number += parameter_string[i];
        }

        if(!str_number.empty())
            result.push_back(stod(str_number));

        return result;
    }
};