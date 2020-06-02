#pragma once
#include "json.h"

/**
 * намира дължината на масив
 * @param word - масивът на които търсим дължианта
 */

int size(const char* word){//pomohsta funciq za duljinata na char*
    int counter = 0;
    for (size_t i = 0; word[i] != '\0'; i++){
        counter++;
    }
    return counter;
}

/**
 * проверява json фаелът дали е валиден като синтаксис изкарва следващата дума след грешната
 * @param file_path - масивът на който искаме да намерим дължината
 */ 

void Json::validate(const char* file_path){

    ifstream input_stream;
    int count_brackets = 0;
    input_stream.open(file_path, ios::in);

    if(input_stream.is_open()) {
        char wordFromFile[char_buffer];
        while(!input_stream.eof()) {
            input_stream >> wordFromFile;
            if(wordFromFile[0] == '{' || wordFromFile[0] == '['){
                count_brackets++;
                continue;
            }else if(wordFromFile[0] == '}' || wordFromFile[0] == ']'){
                if(count_brackets==1 && count_brackets==2 && count_brackets==3){
                    count_brackets--;
                }else {
                    cout<<"check the brakets"<<endl;
                }
                continue;
            }else 
            if((wordFromFile[0] == '"' && wordFromFile[size(wordFromFile)-2] == '"' && wordFromFile[size(wordFromFile)-1] == ':' ) ||
               (wordFromFile[0] == '"' && wordFromFile[size(wordFromFile)-2] == '"' && wordFromFile[size(wordFromFile)-1] == ',' ) ||
               (wordFromFile[0] != '"' && wordFromFile[size(wordFromFile)-1] == ',')){
                  continue;
            }else if((wordFromFile[0] == '"' && wordFromFile[size(wordFromFile)-1] == '"') ||
                     (wordFromFile[0] != '"' && wordFromFile[size(wordFromFile)-1] != ',')){
                    input_stream >> wordFromFile;    
                    if(wordFromFile[0] == '}'){
                        continue;
                    }else{
                        cout<<"the sintax is not valid check: "<< wordFromFile<<endl;
                    }
            }else if(wordFromFile[0] == '"' && wordFromFile[size(wordFromFile)-1] == ' '){
                    while(!wordFromFile[size(wordFromFile)-1] == '"'){
                        input_stream >> wordFromFile;
                        if(wordFromFile[0] == '}' || wordFromFile[0] == '{' || wordFromFile[0] == ']' || wordFromFile[0] == '['){
                            cout<<"the sintax is not valid check: "<< wordFromFile<<endl;
                        }
                    }
                    continue;
            }else{
                cout<<"the sintax is not valid check: "<< wordFromFile<<endl;
            }
        }
        // if(count_brackets != 0){
        //     cout<<"check the brakets"<<endl;
        // }
        input_stream.close();
    }else{
        cout<<"can't open the file";
    }
}