#include<iostream>
#include "command.h"

void Command::close(){

    cout<< "the file was successfuly closed"<<endl;
    file.close();
    
}

void Command::help(){

    cout << "The following commands are supported:\n"
            "open <file>	     opens <file>\n"
            "close			     closes currently opened file\n"
            "save			     saves the currently open file\n"
            "saveas <file>	     saves the currently open file in <file>\n"
            "help			     prints this information\n"
            "exit			     exists the program\n";

}