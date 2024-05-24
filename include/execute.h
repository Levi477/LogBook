#ifndef execute_h
#define execute_h

#include <iostream>
#include <string>

namespace ter{

void makeFolder(const std::string &path,const std::string &folderName);
void makeFile(const std::string &path,const std::string &fileName);
void listAllFiles(const std::string &path);

};

#endif
