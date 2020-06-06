#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;

const int char_buffer = 64;

class Json_struct{
private:
    string _key;
    string _value;
public:
    Json_struct() : _key(""), _value("") {}
    Json_struct(const string &_key, const string &_value) : _key(_key), _value(_value) {}
    Json_struct(const Json_struct &other) : _key(other._key), _value(other._value) {}
    Json_struct& operator=(const Json_struct &other){
        if(this != &other){
            _key = other._key;
            _value = other._value; 
        }

        return *this;
    }

    void set_key(const string &_key){this->_key = _key; }
    void set_value(const string &_value){this->_value = _value; }

    string get_key()const {return this->_key; }
    string get_value()const {return this->_value; }

};

class Json : public Json_struct{
    friend class Json_struct;
private:
    vector<Json_struct> file_contents;
public:

    Json() : file_contents() {}

    Json(const vector<Json_struct> fileContents) : file_contents(file_contents) {}

    Json(const Json &other) : file_contents(other.file_contents) {}
        
    Json& operator=(const Json &other){
        if(this != &other){
            file_contents = other.file_contents;
        }

        return *this;
    }
    
    void validate(const char* file_path);
    void print(const char* file_path);
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