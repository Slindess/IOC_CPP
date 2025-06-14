#ifndef IOC_CPP_TREE_H
#define IOC_CPP_TREE_H

#include <memory>
#include <vector>
#include <string>

class Tree {
public:
    Tree(const std::string& name, std::shared_ptr<Tree> parent, std::vector<std::shared_ptr<Tree>> &&children) :
    _parent(parent), _children(std::move(children)), _name(name), _currentIndex(0) {}

    std::string GetFileName() { return _name; }

    void Begin(int index=0);
    std::shared_ptr<Tree> Next();
    std::shared_ptr<Tree> Prev();

    const std::vector<std::shared_ptr<Tree>> &GetChildren() const { return _children; }

private:
    std::shared_ptr<Tree> _parent;  // Parent Node
    std::vector<std::shared_ptr<Tree>> _children;  // Children nodes
    std::string _name;  // Short Filename
    int _currentIndex;  // Index for Iterator
};


#endif //IOC_CPP_TREE_H
