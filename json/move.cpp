#include "json.h"

/**
 * премества ред от едно място да друго
 * @param from_path - редът който искаме да преместим
 * @param to_path - мястото където искаме да поставим редът
 */ 

void Json::move(const string &from_path, const string &to_path){
    
    int from, to;
    for (int i = 0; i < file_contents.size(); i++){
        if(file_contents[i].get_key() == from_path){
            from = i;
        }
        if(file_contents[i].get_key() == to_path){
            to = i;
        }
    }
    string temp;
    temp = file_contents[to].get_key();
    file_contents[to].set_key(file_contents[from].get_key());
    file_contents[from].set_key(temp);

    cout<<"successfuly moved"<<endl;
}