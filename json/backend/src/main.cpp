#include "json.cpp"
#include "json.h"
#include "create.cpp"
#include "command.cpp"
#include "move.cpp"
#include "print.cpp"
#include "save.cpp"
#include "set.cpp"
#include "validate.cpp"
#include "delete.cpp"


int main(){

    cout<<"in to"<<endl;
    string input;
    getline(cin,input);

    Command commands;
    Json json;

    while(input != "exit"){

        string* words = split(input);
        string command = words[0];

        if(command == "open"){

           all_read("experiment.json");
           json.read_from_file("experiment.json");
           cout<<"the file is succsessfully open"<<endl;

        }else if(command == "close"){

            commands.close();

        }else if(command == "save"){

           json.save_to_file("expo.json");

        }else if(command == "save_as"){

            string file_name = words[1];
            json.save_to_file(file_name);

        }else if(command == "help"){

            commands.help();

        }else if(command == "move"){

            string from_path = words[1];
            string to_path = words[2];
            json.move(from_path, to_path);
            json.save_to_file("expo.json");

        }else if(command == "print"){

            char* file_name = new char[words[1].length()+1];
            strcpy(file_name, words[1].c_str());
            json.print(file_name);
            delete[] file_name;

        }else if(command == "create"){

            string path = words[1];
            string word_for_create = words[2];
            json.create(path, word_for_create);
            json.save_to_file("expo.json");

        }else if(command == "save_file"){

            string path = words[1];
            json.save(path);

        }else if(command == "save_as_file"){

            string file_path = words[1];
            string path = words[2];
            json.save_as(file_path, path);

        }else if(command == "replace"){

            string path = words[1];
            string word_for_repalce = words[2];
            json.set(path, word_for_repalce);
            json.save_to_file("expo.json");

        }else if(command == "validate"){

            char* file_name = new char[words[1].length()+1];
            strcpy(file_name, words[1].c_str());
            json.validate(file_name);
            delete[] file_name;

        }else if(command == "delete"){

            string path = words[1];
            json.deletefunc(path);
            json.save_to_file("expo.json");

        }

        delete[] words;
        getline(cin, input);
    }


}