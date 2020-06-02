#include "json.cpp"

/**
 * принти 
 * @param file_path - името на фаелът който искаме да принтираме
 */ 

void Json::print(const char* file_path){

    ifstream input_stream;
    input_stream.open(file_path, ios::in);

    if(input_stream.is_open()) {
        char lineFromFile[100];
        while(!input_stream.eof()) {
            input_stream.getline(lineFromFile, 100);
            cout << lineFromFile << endl;
        }
        input_stream.close();
    } 
}