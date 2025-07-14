#ifndef IOC_CPP_FILESPARSER_H
#define IOC_CPP_FILESPARSER_H

#include <string>
#include <iostream>
#include <filesystem>
#include <memory>
#include <vector>

#include "../Tree/Tree.h"
#include "FileTypeStrategy/FileTypeStrategy.h"

namespace fs = std::filesystem;

/**
 * @class FilesParser
 * @brief Class for Recursive FS Parsing
*/

class FilesParser {
public:

    /**
     * @brief Constructor.
     * @param projectRootDirName Name of a project root entry.
     * @details Initialize _root.
    */
    explicit FilesParser(const std::string &projectRootDirName) : _projectRootDirName(projectRootDirName),
     _fileTypeStrategy(std::make_unique<FileTypeStrategy>())
    { _root = std::make_shared<Tree>(fs::path(projectRootDirName).filename().string());
        ParseDir(fs::path(projectRootDirName), projectRootDirName); };

    /**
     *
     * @return Returns _root
     */
    std::shared_ptr<Tree> GetRoot() const { return _root; }

private:

    /**
     * @brief Parses a directory and represents its structure as a hierarchical tree of nodes.
     * @details The root of the tree corresponds to the given directory path (`path`).
     *          Each node in the tree represents a file or subdirectory.
     * @param path The filesystem path to the directory to parse
     * @param parent The parent node to which the parsed directory will be attached (can be nullptr for root).
     * @return A shared pointer to the root of the generated tree.
     */
    void ParseDir(const fs::path& path, const std::string &parent);
    std::string _projectRootDirName;
    std::shared_ptr<Tree> _root;
    std::unique_ptr<FileTypeStrategy> _fileTypeStrategy;
};


#endif //IOC_CPP_FILESPARSER_H
