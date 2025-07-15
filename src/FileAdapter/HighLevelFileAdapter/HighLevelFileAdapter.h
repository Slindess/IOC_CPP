#ifndef HIGHLEVELFILEADAPTER_H
#define HIGHLEVELFILEADAPTER_H

#include <memory>
#include <fstream>

#include "../LowLevelFileAdapter/LowLevelFileAdapter.h"
#include "../../Dependency/Dependency.h"

class HighLevelFileAdapter
{
public:
    HighLevelFileAdapter() {lowLevelFileAdapter = std::make_shared<LowLevelFileAdapter>();}
    std::vector<std::shared_ptr<Dependency> > ParseDependenciesFromFile(const std::string &filename);

private:
    std::shared_ptr<LowLevelFileAdapter> lowLevelFileAdapter;

    enum ParsingState 
    {
        searching_class_name = 0,
        checking_is_definition,
        searching_constructor,
        parsing_constructor
    };
};

#endif