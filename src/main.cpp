#include "FilesParser/FilesParser.h"


int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "Неверный путь к папке!" << std::endl;
        return 1;
    }

    std::string directory = argv[1];
    FilesParser parser(directory);

    std::shared_ptr<Tree> root = parser.GetRoot();

    std::function<void(std::shared_ptr<Tree>, int)> print = [&](std::shared_ptr<Tree> node, int depth) {
        if (!node) return;

        for (int i = 0; i < depth; ++i) {
            std::cout << "  ";
        }
        std::cout << node->GetFileName() << '\n';

        for (const auto &child : node->GetChildren()) {
            print(child, depth + 1);
        }
    };

    print(root, 0);

    return 0;
}
