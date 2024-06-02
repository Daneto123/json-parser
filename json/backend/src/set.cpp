#include "json.cpp"

/**
 * намира и заменя дума зададена от потребителя
 * @param file_path - името на фаелът в които искаме заменим думата
 * @param path - думата съседна на търсената
 * @param word_for_replace - думата с която искаме да заменим
 */ 

void Json::set(const string &path, const string &word_for_replace){

    for (int i = 0; i < file_contents.size(); i++){
        if(file_contents[i].get_key() == path){
            file_contents[i].set_key(word_for_replace);
           //cout<<"namerih go";
       }else if(file_contents[i].get_value() == path){
           file_contents[i].set_value(word_for_replace);
       }
    } 
    
    cout<<"successfuly set"<<endl;

}