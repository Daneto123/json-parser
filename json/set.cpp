#include "json.cpp"

/**
 * намира и заменя дума зададена от потребителя
 * @param file_path - името на фаелът в които искаме заменим думата
 * @param path - думата съседна на търсената
 * @param word_for_replace - думата с която искаме да заменим
 */ 

void Json::set(string path, string word_for_replace){

    for (int i = 0; i < fileContents.size(); i++){
        if(fileContents[i].get_key() == path){
            fileContents[i].set_key(word_for_replace);
           //cout<<"namerih go";
       }else if(fileContents[i].get_value() == path){
           fileContents[i].set_value(word_for_replace);
       }
    } 
    
    cout<<"successfuly set"<<endl;

}