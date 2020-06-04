#include "json.h"

/**
 * намира и изтрива дума 
 * @param file_path - името на фаелът в който искаме да работим
 * @param path - думата която искаме да изтрием
 */ 

void Json::deletefunc(const string &path){
    
    for (int i = 0; i < file_contents.size(); i++){
        if(file_contents[i].get_key() == path){
            file_contents[i].set_key("");
            break;
        }else if(file_contents[i].get_value() == path){
            file_contents[i].set_value("");
        }
    }

    // for (size_t i = 0; i < size_of_vector; i++)
    // {
    //     cout<<fileContents[i].get_key()<<endl;
    // }

    cout<<"successfuly removed"<<endl;
}