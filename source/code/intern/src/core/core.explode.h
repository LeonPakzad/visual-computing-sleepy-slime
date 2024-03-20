#pragma once

#include <sstream>
#include <string>
#include <vector>

namespace Core 
{
    std::vector<std::string> Explode(std::string string, const char& delimiter);
}

namespace Core 
{
    inline std::vector<std::string> Explode(std::string string, const char& delimiter) 
    {
        std::string tmpSubString;
        std::stringstream ss(string);
        std::vector<std::string> subStrings;

        while (getline(ss, tmpSubString, delimiter))
        {
            subStrings.push_back(tmpSubString);
        }

        return subStrings;
    }
}