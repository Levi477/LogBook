#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>

class folder {
public:
    std::string name;
    std::string tag;
    std::string date;
    std::string time;
    std::string path;

    void getname();
    void gettag();
};

class file {
public:
    std::string name;
    std::string tag;
    std::string date;
    std::string time;
    std::string path;

    void getname();
    void gettag();
};

class path {
public:
    std::string path;

    void getpath();
};

#endif 
