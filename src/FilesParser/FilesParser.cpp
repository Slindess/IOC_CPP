#include "FilesParser.h"

std::shared_ptr<Tree> FilesParser::ParseDir(const fs::path& path, std::shared_ptr<Tree> parent)
{
    std::vector<std::shared_ptr<Tree>> children;

    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_directory()) {
            children.push_back(ParseDir(entry.path(), parent));
        } else {
            std::vector<std::shared_ptr<Tree>> childrenEmpty;
            childrenEmpty.clear();
            children.push_back(std::make_shared<Tree>(entry.path().filename().string(), parent, std::move(childrenEmpty)));
        }
    }

    auto node = std::make_shared<Tree>(path.filename().string(), parent, std::move(children));

    return node;
}
