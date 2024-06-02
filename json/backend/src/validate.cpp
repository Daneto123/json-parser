#include "json.h"

/**
 * проверява json фаелът дали е валиден като синтаксис изкарва следващата дума след грешната
 * @param file_path - масивът на който искаме да намерим дължината
 */ 

void Json::validate(const char* file_path){

    ifstream input_stream;
    bool flag = true;
    int count_brackets = 0;
    input_stream.open(file_path, ios::in);

    if(input_stream.is_open()) {
        string word = "";
        while(!input_stream.eof()) {
            input_stream >> word;
            if(word == "{" || word == "["){
                count_brackets++;
                continue;
            }else if((word.find(":") != string::npos) || (word.find(",") != string::npos)){
                    if(word == "],"){
                        count_brackets--;
                    }
                  continue;
            }else if(!(word.find(",") != string::npos)){
                    input_stream>>word;
                    if(word == "}" || word == "},"){
                        count_brackets--;
                        continue;
                    }else{
                        cout<<"the sintax is not valid check: "<< word<<endl;
                        flag = false;
                    }
            }else{
                cout<<"the sintax is not valid check: "<< word<<endl;
                flag = false;
            }
        }
        if(count_brackets == 0){
            cout<<"brakets is correct"<<endl;
            flag = true;
        }else{
            cout<<"check the brakets"<<endl;
            flag = false;
        }

        input_stream.close();

    }else{
        cout<<"can't open the file"<<endl;
    }

    if(flag == true){
        cout<<"file is correct"<<endl;
    }

}