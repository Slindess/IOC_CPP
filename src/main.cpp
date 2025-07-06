#include <iostream>
#include "FilesParser/FilesParser.h"


int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "Неверный путь к папке!" << std::endl;
        return 1;
    }

    std::string directory = argv[1];
    std::cout << directory << std::endl;
    FilesParser parser(directory);
    std::shared_ptr<Tree> project = parser.GetRoot();

    std::cout << directory << std::endl;
    for (auto it = project->begin(); it != project->end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}
