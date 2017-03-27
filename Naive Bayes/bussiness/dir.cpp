#include <string>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main()
{
    std::string path = "path_to_directory";
    for (auto & p : fs::directory_iterator(path))
        std::cout << p << std::endl;
}