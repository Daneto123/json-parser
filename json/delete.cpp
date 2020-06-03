#include "json.h"

/**
 * намира и изтрива дума 
 * @param file_path - името на фаелът в който искаме да работим
 * @param path - думата която искаме да изтрием
 */ 

void Json::deletefunc(const string &path){
    
    for (int i = 0; i < fileContents.size(); i++){
        if(fileContents[i].get_key() == path){
            fileContents[i].set_key("");
            break;
        }else if(fileContents[i].get_value() == path){
            fileContents[i].set_value("");
        }
    }

    // for (size_t i = 0; i < size_of_vector; i++)
    // {
    //     cout<<fileContents[i].get_key()<<endl;
    // }

    cout<<"successfuly removed"<<endl;
}