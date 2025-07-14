#ifndef IOC_CPP_TREE_H
#define IOC_CPP_TREE_H

#include "Enums/FileType.h"
#include <memory>
#include <stdexcept>
#include <vector>
#include <string>
#include <stack>

class Tree {
private:
    struct Node
    {
        std::string filename;
        std::vector< std::shared_ptr<Node> > children; 
        FileType filetype;

        Node(const std::string& name)
            : filename(name), filetype(FileType::other) {}

        Node(const std::string& name, FileType type)
            : filename(name), filetype(type) {}
    };

public:
    class Iterator;
    friend class Iterator;   
    using value_type = std::string;
    using reference = std::string&;

    Iterator begin();
    Iterator end();
    
    Tree(const std::string &root_name)
    {
        _root = std::make_shared<Node>(root_name, FileType::directory);
    }

    void AddChild(const std::string &name, const std::string parent_name, FileType type);


private:
    std::shared_ptr<Node> _root;
};

class Tree::Iterator
{
private:
    friend class Tree;
    using Node = Tree::Node;
    std::stack< std::shared_ptr<Node> > stack;
    std::shared_ptr<Node> current;
    bool isEnd;

public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = std::string;
    using reference = std::string&;
    using difference_type = std::ptrdiff_t;
    using pointer = std::shared_ptr<std::string>;

    explicit Iterator(std::shared_ptr<Node> root)
    {
        if (root == nullptr)
        {
            current = nullptr;
            isEnd = true;
        }
        else
        {
            isEnd = false;
            stack.push(root);
            ++(*this);
        }
    }



    reference operator*() const
    { 
        if (current == nullptr )
        {
            static std::string empty_string;
            return empty_string;
        }
        else return current->filename; 
    }
    pointer operator->() const { return std::make_shared<std::string>(current->filename); }

    Iterator& operator++()
    {
        if (stack.empty())
        {
            current = nullptr;
            isEnd = true;
            return *(this);
        }

        current = stack.top();
        stack.pop();

        for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
            stack.push(*it);
        }

        return *this;
    }

    FileType GetFileType()
    {
        return current->filetype;
    }

    Iterator operator++(int)
    {
        Iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    bool operator==(const Iterator &other)
    {
        return current == other.current;
    }

    bool operator!=(const Iterator &other)
    {
        return !(*this == other);
    }

private:
    std::shared_ptr<Node> GetNode() const { return current; }

};

#endif //IOC_CPP_TREE_H
