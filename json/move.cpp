#include "json.h"

/**
 * премества ред от едно място да друго
 * @param from_path - редът който искаме да преместим
 * @param to_path - мястото където искаме да поставим редът
 */ 

void Json::move(const string &from_path, const string &to_path){
    
    int from, to;
    for (int i = 0; i < fileContents.size(); i++){
        if(fileContents[i].get_key() == from_path){
            from = i;
        }
        if(fileContents[i].get_key() == to_path){
            to = i;
        }
    }
    string temp;
    temp = fileContents[to].get_key();
    fileContents[to].set_key(fileContents[from].get_key());
    fileContents[from].set_key(temp);

    cout<<"successfuly moved"<<endl;
}