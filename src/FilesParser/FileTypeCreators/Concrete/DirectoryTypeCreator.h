#ifndef DIRECTORYFILETYPECREATOR_H
#define DIRECTORYFILETYPECREATOR_H

#include "../BaseFileTypeCreator.h"

class DirectoryFileTypeCreator : public BaseFileTypeCreator
{
public:
    FileType CreateFileType(std::string file_name) override {return FileType::directory;}
};

#endif