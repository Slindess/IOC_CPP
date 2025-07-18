#include "FilesParser.h"
#include "FileTypeStrategy/FileTypeStrategy.h"

void FilesParser::ParseDir(const fs::path& path, const std::string &parentName)
{
    try {
        for (const auto& entry : fs::directory_iterator(path)) {
            const std::string filename = entry.path().string();
            
            if (entry.is_directory()) {
                _root->AddChild(filename, parentName, _fileTypeStrategy->GetFileType(entry));
                ParseDir(entry.path(), filename);
            } else {
                _root->AddChild(filename, parentName, _fileTypeStrategy->GetFileType(entry));
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Error parsing directory: " << e.what() << '\n';
    }
}
