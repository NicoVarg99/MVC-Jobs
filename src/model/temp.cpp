#include <iostream>
#include <fstream>
#include <string>

#define SLASH "/"

#define DEBUG 1

using namespace std;

int main(){

    string fileName = "data";
    fileName+=SLASH;
    fileName+="students.bin";
    streampos begin,end;
    //ofstream file(fileName.c_str(), ios::out | ios::binary);
    ifstream file(fileName.c_str(), ios::in | ios::binary);
    if(file.is_open())
    {
        begin=file.tellg();
        file.seekg(0,ios::end);
        end=file.tellg();
        int n=5;
        //file.write((char*)&n,sizeof(int));
        //if(DEBUG) cout << "Writed" << endl;
        file.read((char*)&n,sizeof(int));
        if(DEBUG) cout << "readed" << endl;
        if(DEBUG) cout << "Number of students:  " << n << endl;
    }
    else
    {
        if(DEBUG)
            cout << "Unable to open file:  " << fileName << endl;
        return NULL;
    }
}
