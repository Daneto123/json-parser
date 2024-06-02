#pragma once
#include<fstream>
#include<vector>
using namespace std;

class Command{
protected:
    fstream file;

public:

    void close();
    void help();

};