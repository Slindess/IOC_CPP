#include "Tree.h"
#include "Enums/FileType.h"

Tree::Iterator Tree::begin()
{
    return Iterator(_root);
}

Tree::Iterator Tree::end()
{
    return Iterator(nullptr);
}

void Tree::AddChild(const std::string &name, const std::string parent_name, FileType type)
{
    std::shared_ptr<Node> parent_node = nullptr;

    for (auto it = begin(); it != end(); ++it)
    {
        if (*it == parent_name)
        {
            parent_node = it.GetNode();
        }
    }

    if (!parent_node)
    {
        throw std::runtime_error("Parent node '" + parent_name + "' not found");
    }

    parent_node->children.push_back(std::make_shared<Node>(name, type));
}
