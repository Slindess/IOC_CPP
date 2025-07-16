#include <iostream>
#include "FilesParser/FilesParser.h"
#include "FileAdapter/HighLevelFileAdapter/HighLevelFileAdapter.h"
#include "Tree/Enums/FileType.h"



int main(int argc, char* argv[])
{
    
    if (argc < 2) {
        std::cerr << "Неверный путь к папке!" << std::endl;
        return 1;
    }
    
    std::string directory = argv[1];
    FilesParser parser(directory);
    std::shared_ptr<Tree> project = parser.GetRoot();

    HighLevelFileAdapter fileAdapter;

    for (auto it = project->begin(); it != project->end(); ++it)
    {
        std::cout << *it << " " << it.GetFileType() << std::endl;
        if (it.GetFileType() == FileType::header_cpp)
            fileAdapter.ParseDependenciesFromFile(*it);
    }
    
    return 0;
}
