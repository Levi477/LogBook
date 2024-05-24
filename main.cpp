#include <iostream>
#include "include/execute.h"
#include "include/classes.h"
#include <string>
#include <filesystem>

namespace fs = std::filesystem;



int main() {

    folder myfolder;
    file myfile;
    path mypath;

    char main_menu_ans;

    while(main_menu_ans != 'q'){

        std::cout << std::endl << std::endl;
        std::cout << "################################################" << std::endl;
        std::cout << "Current Path : " << mypath.path << std::endl;
        std::cout << "Current Folder Path : " << myfolder.path << std::endl; 
        std::cout << "Current File Path : " << myfile.path << std::endl;
        std::cout << "################################################" << std::endl;

        std::cout << std::endl;
        std::cout << "1.make a working folder" << std::endl;
        std::cout << "2.make a file inside working folder" << std::endl;
        std::cout << "3.remove working directory" << std::endl;
        std::cout << "4.remove a file" << std::endl;
        std::cout << "5.list all files inside current directory" << std::endl;
        std::cout << "6.update your path" << std::endl;
        std::cout << "q.quit" << std::endl;

        std::cout << "---------------------------------------------" << std::endl;
        std::cout << ">> ";
        std::cin >> main_menu_ans ;

        switch(main_menu_ans){

            case '1':

            mypath.getpath();
            myfolder.getname();
            myfolder.gettag();

            ter::makeFolder(mypath.path,myfolder.name);

            if(fs::exists(mypath.path + '/' + myfolder.name)){
                std::cout << "Working folder created succesfully!" << std::endl;
                myfolder.path = mypath.path + '/' + myfolder.name;
            }
            else{
                std::cerr << "Failed creating working folder" << std::endl;
            }            

            break;

            case '2':

            if(fs::exists(myfolder.path)){
               
                myfile.getname();
                myfile.gettag();
                
                ter::makeFile(myfolder.path,myfile.name);
                myfile.path = myfolder.path + '/' + myfile.name;

                if(fs::exists(myfolder.path + '/' + myfile.name)){
                    std::cout << "File created succesfully!" << std::endl;
                }
                else{
                    std::cerr << "Failed creating file" << std::endl;
                }

            }
            else{
                std::cerr << "Pls create working folder first" << std::endl;
            }

            break;

            case '3':

            if(fs::exists(myfolder.path)){
                fs::remove_all(myfolder.path);
                std::cout << "Folder removed successfully!" << std::endl;
            }
            else{
                std::cout << "Enter path to working directory : ";
                std::cin >> myfolder.path;

                fs::remove_all(myfolder.path);
                std::cout << "Folder removed successfully!" << std::endl;
            }
            break;

            case '4':

            if(fs::exists(myfile.path)){
                fs::remove(myfile.path);
                std::cout << "File removed successfully!" << std::endl;
            }
            else{
                std::cout << "Enter path to file : ";
                std::cin >> myfile.path;

                fs::remove_all(myfile.path);
                std::cout << "File removed successfully!" << std::endl;
            }
            break;

            case '5':

            if(fs::exists(mypath.path)){
                ter::listAllFiles(mypath.path);
            }
            else{
            std::cout << "Enter path to current directory : ";
            std::cin >> mypath.path;
            ter::listAllFiles(mypath.path);
            }
            break;

            case '6':

            char temp_ans;

            std::cout << "Your current working directory : " << mypath.path << std::endl;
            std::cout << "Do you want to update your path to working directory(y/n) : ";
            std::cin >> temp_ans;

            if(temp_ans == 'y' || temp_ans == 'Y'){
                std::cout << "Enter your path : ";
                std::cin >> mypath.path; 
                std::cout << "Updated your path succesfully!" << std::endl;
            }
            
            break;

            default:
            if(main_menu_ans != 'q'){
            std::cout << "Pls select proper option!!" << std::endl;
            }
            break;



    }

   
}

 std::cout << "Thank you!!" << std::endl;
    
    return 0;

}
