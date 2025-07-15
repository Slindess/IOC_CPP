#ifndef DEPENDENCY_H
#define DEPENDENCY_H

#include <string>

class Dependency
{
public:
    Dependency(const std::string &className, const std::string &fileName) : 
    classname(className), filename(fileName) {}

    void addDependecy(const std::string &dependency)
    {
        dependencies.push_back(dependency);
    }

private:
    std::string filename;
    std::string classname;
    std::vector<std::string> dependencies;
};

#endif