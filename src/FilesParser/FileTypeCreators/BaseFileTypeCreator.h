#ifndef BASEFILETYPECREATOR_H
#define BASEFILETYPECREATOR_H

#include <string>

#include "../../Tree/Enums/FileType.h"

class BaseFileTypeCreator
{
public:
    virtual FileType CreateFileType(std::string file_name) = 0;
    virtual ~BaseFileTypeCreator() = default;
};

#endif