#ifndef IOC_CPP_FILESPARSER_H
#define IOC_CPP_FILESPARSER_H

#include <string>
#include <iostream>
#include <filesystem>
#include <memory>
#include <vector>

#include "../Tree/Tree.h"

namespace fs = std::filesystem;

class FilesParser {
public:
    explicit FilesParser(std::string &projectRootDirName) : _projectRootDirName(projectRootDirName)
    { _root = ParseDir(_projectRootDirName, nullptr); };
    std::shared_ptr<Tree> GetRoot() const { return _root; }

private:

    std::shared_ptr<Tree> ParseDir(const fs::path& path, std::shared_ptr<Tree> parent);
    std::string _projectRootDirName;
    std::shared_ptr<Tree> _root;
};


#endif //IOC_CPP_FILESPARSER_H
