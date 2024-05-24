#include "../include/execute.h"
#include <filesystem>
#include <string>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;
using ofs = std::ofstream;
using ifs = std::ifstream;

namespace ter {

void makeFolder(const std::string &path, const std::string &folderName){
    fs::create_directories(path + "/" + folderName);
    if(!fs::exists(path + "/" + folderName)){
        std::cerr << "Failed to create " << folderName <<" folder " << std::endl;
    }
}

void makeFile(const std::string &path, const std::string &fileName){
    ofs file(path + "/" + fileName);
    if (!file) {
        std::cerr << "Failed to create file: " << path + "/" + fileName << std::endl;
    }
}


void listAllFiles(const std::string &path)
{
    for (const auto &entry : fs::directory_iterator(path)) {
        std::cout << entry.path().string() << std::endl;
    }
}
}
