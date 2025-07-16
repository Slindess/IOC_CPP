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

        std::unique_ptr<BaseFileTypeCreator> filetype_creator = it->second();

        return filetype_creator->CreateFileType(entry.path().string());
    }

private:
    std::map<std::filesystem::file_type, std::function<std::unique_ptr<BaseFileTypeCreator> ()> > strategy_map = 
    {
        {std::filesystem::file_type::regular, []() { return std::make_unique<RegularFileTypeCreator>();} },
        {std::filesystem::file_type::directory, []() { return std::make_unique<DirectoryFileTypeCreator>();} },
        {std::filesystem::file_type::symlink, []() { return std::make_unique<OtherFileTypeCreator>();} },
        {std::filesystem::file_type::block, []() { return std::make_unique<OtherFileTypeCreator>();} },
        {std::filesystem::file_type::character, []() { return std::make_unique<OtherFileTypeCreator>();} },
        {std::filesystem::file_type::fifo, []() { return std::make_unique<OtherFileTypeCreator>();} },
        {std::filesystem::file_type::socket, []() { return std::make_unique<OtherFileTypeCreator>();} },
        {std::filesystem::file_type::unknown, []() { return std::make_unique<OtherFileTypeCreator>();} },
        {std::filesystem::file_type::none, []() { return std::make_unique<OtherFileTypeCreator>();} },
        {std::filesystem::file_type::not_found, []() { return std::make_unique<OtherFileTypeCreator>();} }
    };
};

#endif