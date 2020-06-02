#include "json.cpp"

/**
 * запазва елемент в файл
 * @param path - редът които искаме да запазим
 */ 

void Json::save(string path){

    char file_path[16] = "exp.json";

    fstream file1; 
    file1.open(file_path);

    char word_form_file[char_buffer];

    if (file1.is_open()){ 
        while(!file1.eof()){
            file1 >> word_form_file;
            if(word_form_file == path){
                file1 >> word_form_file;
                file1 << word_form_file << endl;
            }
        }
        file1.close(); 
    }
}

/**
 * намира дължината на чар*
 * @param path - пътят до елементът който искаме да презапишем
 */ 

void Json::saveas(string path){//da zapazva dadeniqt red v file koito potrebitelqt iska

    char file_path[16] = "exp.json";

    fstream file1; 
    file1.open(file_path);

    char word_form_file[char_buffer];

    if (file1.is_open()){
        while(!file1.eof()){ 
            file1 >> word_form_file;
            if(word_form_file == path){
                //file1 >> word_form_file;
                file1 << word_form_file << endl;
            }
        }
        file1.close(); 
    }
}