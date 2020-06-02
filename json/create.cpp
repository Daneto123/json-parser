#include "json.h"

/**
 * по зададен път да добавим дума в фаелът
 * @param file_path - името на фаелът с който искаме да работим
 * @param path - думата съседна на търсената
 * @param word_for_create - думата която искаме да създадем
 */ 

void Json::create(const string &path, const string &word_for_create){

    string new_word;

    for (int i = 0; i < fileContents.size(); i++){
        if(fileContents[i].get_key() == path){
            //cout<<word_for_create;
            new_word = " " + fileContents[i].get_key() + " " + word_for_create;
            fileContents[i].set_key(new_word);

        }else if(fileContents[i].get_value() == path){
            new_word = " " + fileContents[i].get_value() + " " + word_for_create;
            fileContents[i].set_value(new_word);

        }
    }

    cout<<"successfuly created"<<endl;
}