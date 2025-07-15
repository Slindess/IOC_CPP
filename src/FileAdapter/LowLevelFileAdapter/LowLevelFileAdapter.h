#ifndef LOWLEVELFILEADAPTER_H
#define LOWLEVELFILEADAPTER_H

#include <memory>
#include <string>
#include <fstream>

class LowLevelFileAdapter
{
public:
   std::fstream openCreate(const std::string &filename);
   std::fstream openReadWriteAppend(const std::string &filename);
   std::fstream openReadWriteAppendOrCreate(const std::string &filename);
   std::fstream openRead(const std::string &filename);

private:
    bool fileExists(const std::string &filename);
};


#endif