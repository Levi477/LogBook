#include "../include/classes.h"

void folder::getname() {
    std::cout << "Enter name for working folder : ";
    getline(std::cin >> std::ws,name);
}

void folder::gettag() {
    char ans;
    std::cout << "Do you want to add tag to folder (y/n) : ";
    std::cin >> ans;

    if (ans == 'y' || ans == 'Y') {
        std::cout << "Enter tag for working folder : "; 
        getline(std::cin >> std::ws,tag);
    }
}

void file::getname() {
    std::cout << "Enter name for file : "; 
    getline(std::cin >> std::ws,name);
}

void file::gettag() {
    char ans;
    std::cout << "Do you want to add tag to file (y/n) : ";
    std::cin >> ans;

    if (ans == 'y' || ans == 'Y') {
        std::cout << "Enter tag for file : "; 
        getline(std::cin >> std::ws,tag);
    }
}

void path::getpath() {
    std::cout << "Enter path to working directory : ";
    getline(std::cin >> std::ws,path);
}
