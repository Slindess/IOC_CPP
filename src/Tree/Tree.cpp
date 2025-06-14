#include "Tree.h"

void Tree::Begin(int index)
{
    if (index < 0) index = 0;
    if (index >= static_cast<int>(_children.size()))
    {
        index = static_cast<int>(_children.size()) - 1;
    }
    _currentIndex = index;
}

std::shared_ptr<Tree> Tree::Next()
{
    if (_currentIndex + 1 < static_cast<int>(_children.size()) ) {
        _currentIndex++;
        return _children[_currentIndex];
    }
    return nullptr;
}

std::shared_ptr<Tree> Tree::Prev() {
    if (_currentIndex - 1 >= 0) {
        _currentIndex--;
        return _children[_currentIndex];
    }
    return nullptr;
}