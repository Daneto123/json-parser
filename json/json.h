#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;

const int char_buffer = 64;

class Json_struct{
private:
    string key;
    string value;
public:
    Json_struct() : key(""), value("") {}
    Json_struct(const string &key, const string &value) : key(key), value(value) {}
    Json_struct(const Json_struct &other) : key(other.key), value(other.value) {}
    Json_struct& operator=(const Json_struct &other){
        if(this != &other){
            key = other.key;
            value = other.value; 
        }

        return *this;
    }

    void set_key(const string &key){this->key = key; }
    void set_value(const string &value){this->value = value; }

    string get_key()const {return this->key; }
    string get_value()const {return this->value; }

};

class Json : public Json_struct{
    friend class Json_struct;
private:
    vector<Json_struct> fileContents;
public:

    Json() : fileContents() {}

    Json(const vector<Json_struct> fileContents) : fileContents(fileContents) {}

    Json(const Json &other) : fileContents(other.fileContents) {}
        
    Json& operator=(const Json &other){
        if(this != &other){
            fileContents = other.fileContents;
        }

        return *this;
    }
    
    void validate(const char* file_path);
    void print(const char* file_path);
    void search(const string &key);
    void set(const string &path, const string &word_for_replace);
    void create(const string &path, const string &word_for_create);
    void deletefunc(const string &path);
    void move(const string &from_path, const string &to_path);
    void save(const string &path);
    void save_as(const string &file_path, const string &path);
    void read_from_file(const string &file_path);
    void print_vector();
    void save_to_file(const string &file_path);

};