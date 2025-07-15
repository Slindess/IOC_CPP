#include "LowLevelFileAdapter.h"
#include <fstream>
#include <ostream>


std::fstream LowLevelFileAdapter::openCreate(const std::string &filename)
{
    std::fstream f(filename, std::ios::out);
    return f;
}

std::fstream LowLevelFileAdapter::openReadWriteAppend(const std::string &filename)
{
    std::fstream f(filename, std::ios::in | std::ios::out | std::ios::app);
    return f;
}

std::fstream LowLevelFileAdapter::openReadWriteAppendOrCreate(const std::string &filename)
{
    if (!fileExists(filename))
    {
        std::ofstream f(filename);
        f.close();
    }
 
    return openReadWriteAppend(filename);
}

std::fstream LowLevelFileAdapter::openRead(const std::string &filename)
{
    std::fstream f(filename, std::ios::in);
    return f;
}

bool LowLevelFileAdapter::fileExists(const std::string &filename)
{
    std::ifstream f(filename);

    return f.good();
}