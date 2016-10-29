#include "model.h"

#include <string>
#include <fstream>

#include <iostream> //provvisorio

using namespace std;

bool model_checkFile (const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}

int model_checkDB(){
	return model_checkFile("data/database.bin");
}

int model_createDB(){
	return 0;
}

//check if file exists
//if exists
				//list all students with their current job
				//
				//while(model_isDataAvailable){
				//      view_printStudentList(model_getData("firstName"),model_getData("lastName"),mod$
				//      model_pop();
				//}
				//NOTE: Do not print anything. That is view's job
				//      Ask Mirco for adequate functions if needed.
//if not
				//print an error message
				//view_error("Data file not found.");
/*

struct Student * model_loadStudents(){

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
        struct Student * students;
        students = new struct Student [n];
        for(int i=0;i<n;i++)
        {
            file.read((char*)&students[i],sizeof(struct Student));
        }
        return students;
    }
    else
    {
        if(DEBUG)
            cout << "Unable to open file:  " << fileName << endl;
        return NULL;
    }
}

*/
