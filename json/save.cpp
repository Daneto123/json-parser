#include "json.cpp"

/**
 * запазва елемент в файл
 * @param path - редът които искаме да запазим
 */ 

void Json::save(const string &path){

    string file_path = "exp.json";

    fstream file1; 
    file1.open(file_path);

    if (file1.is_open()){ 
        file1 << path;
        file1.close(); 
        cout<<"successfully save word to file "<<file_path<<endl;
    }else{
        cout<<"can't open the file"<<endl;
    }
}

/**
 * намира дължината на чар*
 * @param path - пътят до елементът който искаме да презапишем
 */ 

void Json::save_as(const string &file_path, const string &path){//da zapazva dadeniqt red v file koito potrebitelqt iska

    fstream file1; 
    file1.open(file_path);

    if (file1.is_open()){
        file1 << path;
        file1.close();
        cout<<"successfully save word to file "<<file_path<<endl;
    }else{
        cout<<"can't open the file"<<endl;
    }
}