#include "HighLevelFileAdapter.h"
#include <climits>
#include <cstddef>
#include <fstream>
#include <stdexcept>
#include <string>
#include <iostream>

std::vector<std::shared_ptr<Dependency> > HighLevelFileAdapter::ParseDependenciesFromFile(const std::string &filename)
{
    std::fstream f = lowLevelFileAdapter->openRead(filename);
    if (!f.good())
        throw std::runtime_error("Can't open file '" + filename + "' to read.");

    std::string line;
    std::string classline = "class ";

    ParsingState currentState = ParsingState::searching_class_name;

    while (std::getline(f, line))
    {
        switch (currentState)
        {
            case ParsingState::searching_class_name:
                size_t pos = line.find(classline);
                if (pos != std::string::npos)
                {
                    std::cout << line.substr(pos + strlen("class ")) << std::endl;
                }

                currentState = ParsingState::checking_is_definition;
                break;
            
            case ParsingState::checking_is_definition:
                
        }

    std::vector<std::shared_ptr<Dependency> > v;
    return v;
}

