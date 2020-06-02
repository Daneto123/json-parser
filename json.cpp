//S POMOSHTA NA BOG SE SLUCHVA VSICHKO
#pragma once
#include "json.h"

vector<string> local_read;

/**
 * служи за четене от фаел
 * @param file_path - името на фаелът който искаме да прочетем
 */

void Json::read_from_file(const string &file_path){

    ifstream file;
    file.open(file_path);
    if (file.is_open()){

        string key = "", value = "", check = "", words = "";

        while (!file.eof()){

            file>>check;
            if(check != "{" && check != "}," && check != "[" && check != "]," && check != "}"){
                file>>value;
                if(value != "{" && value != "[" && value != "}"){
                    fileContents.push_back(Json_struct(check,value));
                }
            }else{
                file>>key>>value;
                if(key == "],"){
                    file>>words;
                    if(words != "[],"){
                        fileContents.push_back(Json_struct(key,value));
                    }
                }else if(value != "["){
                    fileContents.push_back(Json_struct(key,value));
                }
            }
        }
    }else{
        cout<<"error";
    }
}

void all_read(const string &file_path){
    ifstream file;
    file.open(file_path);
    if (file.is_open()){

        string word;
        while(!file.eof()){
            file>>word;
            local_read.push_back(word);
        }
    }
}

/**
 * служи за принтиране на вектор
 */

void Json::print_vector(){

    for (int i = 0; i < fileContents.size(); i ++){
        //cout<<;
        cout << fileContents[i].get_key() << " " << fileContents[i].get_value() << endl;
    }  

    for (int i = 0; i < local_read.size(); i ++){
        //cout<<;
        cout << local_read[i] << endl;
    }  
}

/**
 * служи за запазване на информация от фаел
 * @param file_path - името на фаелът който искаме да прочетем
 */

void Json::save_to_file(string file_path){
    
    fstream file;
    file.open(file_path);
    int count_vector;

    if(file.is_open()) {
        for (size_t k = 0; k < local_read.size(); k++){
            if(local_read[k] == "{" || local_read[k] == "}" || local_read[k] == "}," || local_read[k] == "],"){
                   file<<local_read[k]<<endl;   
            }else if(local_read[k+1] == "{" || local_read[k+1] == "[" || local_read[k+1] == "[],"){
                file<<local_read[k]<<" "<<local_read[k+1]<<endl;
                k++;
            }else if(local_read[k].find('"') != string::npos && count_vector <= fileContents.size()){
                file<<" "<<fileContents[count_vector].get_key()<<" "<<fileContents[count_vector].get_value()<<endl;
                count_vector++;
                k ++;
            }
        }
        file.close();
    }else{
        cout<<"error";
    } 
}

string* split(const string &input){
    
    string* words = new string[5];
    int counter;

    string word = "";
    for(auto x : input){
        if(x == ' '){
            words[counter] = word;
            counter++;
            word = "";
        }else{
            word = word + x;
        }
        words[counter] = word;
    }

    return words;

    delete[] words;

}