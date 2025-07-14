#ifndef FILETYPESTRATEGY_H
#define FILETYPESTRATEGY_H

#include <map>
#include <filesystem>
#include <stdexcept>
#include <memory>

#include "../FileTypeCreators/BaseFileTypeCreator.h"
#include "../FileTypeCreators/Concrete/DirectoryTypeCreator.h"
#include "../FileTypeCreators/Concrete/OtherTypeCreator.h"
#include "../FileTypeCreators/Concrete/RegularTypeCreator.h"

class FileTypeStrategy
{
public:
    FileType GetFileType(std::filesystem::directory_entry entry)
    {
        std::filesystem::file_type file_type = entry.status().type();
        auto it = strategy_map.find(file_type);
        
        if (it == strategy_map.end())
            throw std::runtime_error("Unknown file type.");

        std::shared_ptr<BaseFileTypeCreator> filetype_creator = it->second;

        return filetype_creator->CreateFileType(entry.path().string());
    }

private:
    std::map<std::filesystem::file_type, std::shared_ptr<BaseFileTypeCreator> > strategy_map = 
    {
        {std::filesystem::file_type::regular, std::make_shared<RegularFileTypeCreator>()},
        {std::filesystem::file_type::directory, std::make_shared<DirectoryFileTypeCreator>()},
        {std::filesystem::file_type::symlink, std::make_shared<OtherFileTypeCreator>()},
        {std::filesystem::file_type::block, std::make_shared<OtherFileTypeCreator>()},
        {std::filesystem::file_type::character, std::make_shared<OtherFileTypeCreator>()},
        {std::filesystem::file_type::fifo, std::make_shared<OtherFileTypeCreator>()},
        {std::filesystem::file_type::socket, std::make_shared<OtherFileTypeCreator>()},
        {std::filesystem::file_type::unknown, std::make_shared<OtherFileTypeCreator>()},
        {std::filesystem::file_type::none, std::make_shared<OtherFileTypeCreator>()},
        {std::filesystem::file_type::not_found, std::make_shared<OtherFileTypeCreator>()}
    };
};

#endif