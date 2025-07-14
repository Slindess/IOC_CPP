#ifndef OTHERFILETYPECREATOR_H
#define OTHERFILETYPECREATOR_H

#include "../BaseFileTypeCreator.h"

class OtherFileTypeCreator : public BaseFileTypeCreator
{
public:
    FileType CreateFileType(std::string file_name) override {return FileType::other;}
};

#endif