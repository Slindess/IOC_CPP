#ifndef REGULARFILETYPECREATOR_H
#define REGULARFILETYPECREATOR_H

#include <string>

#include "../BaseFileTypeCreator.h"

class RegularFileTypeCreator : public BaseFileTypeCreator
{
public:
    FileType CreateFileType(std::string file_name) override 
    {
        std::string h_ext {".h"};
        std::string cpp_ext {".cpp"};
        
        FileType type = FileType::other;

        if (file_name.ends_with(h_ext))
            type = FileType::header_cpp;
        else if (file_name.ends_with(cpp_ext))
            type = FileType::cpp;
        
        return type;

    }
};

#endif