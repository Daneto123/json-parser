#include "json.cpp"

/**
 * принти 
 * @param file_path - името на фаелът който искаме да принтираме
 */ 

void Json::print(const char* file_path){

    ifstream input_stream;
    input_stream.open(file_path, ios::in);

    if(input_stream.is_open()) {
        string lineFromFile;
        while(!input_stream.eof()) {
            getline(input_stream, lineFromFile);
            cout << lineFromFile << endl;
        }

        input_stream.close();
    }else{
        cout<<"can't open the file"<<endl;
    }

}