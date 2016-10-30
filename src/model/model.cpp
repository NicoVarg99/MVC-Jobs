#include "model.h"

#include <string>
#include <fstream>

#include <iostream> //provvisorio

using namespace std;

bool model_checkFile (const std::string& name){
    ifstream myfile (name.c_str(), ios::binary | ios::in);
    if (myfile.is_open()){
        myfile.close();
        return true;
    }
    return false;
}

bool model_checkDB(){
    string name="data";
    name+=SLASH;
    name+="database.bin";
	return model_checkFile(name);
}

bool model_createDB(){
    if(!model_checkDB()){
        string name="data";
        name+=SLASH;
        name+="database.bin";
        ofstream myfile (name.c_str(), ios::binary | ios::out);
        if(myfile.is_open()){
            int n=0;
            myfile.write((char *)&n, sizeof(int)); // setto il numero di studenti a 0
            myfile.close();
            return true;
        }
        return false;
    }
    return true;
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

struct Student * model_loadStudents(){
    if(!model_checkDB()){ // se il file non esiste o non riesce ad aprirlo
        model_createDB();
        return NULL;
    }
    string fileName = "data";
    fileName+=SLASH;
    fileName+="database.bin";
    ifstream file(fileName.c_str(), ios::in | ios::binary);
    if(file.is_open())
    {
        int n;
        file.read((char*)&n,sizeof(int));
        if(DEBUG) cout << "readed" << endl;
        if(DEBUG) cout << "Number of students:  " << n << endl;
        Student * students;
        students = new Student [n];
        for(int i=0;i<n;i++)
        {
            file.read((char*)&students[i],sizeof(struct Student));
            students[i].job=new Job [students[i].jobsNum];
            for(int j=0; j<students[i].jobsNum; j++)
            {
                file.read((char*)&students[i].job[j],sizeof(struct Job));
            }
        }
        return students;
    }
    else
    {
        if(DEBUG)
            cout << "Unable to open file:  " << fileName << endl;
        return NULL;
    }
    file.close();
}

bool model_writeStdents(struct Student *students, int numberOfStudents)
{
    if(!model_createDB())
        return false;
    string fileName="data";
    fileName+=SLASH;
    fileName+="database.bin";
    ofstream file (fileName.c_str(), ios::binary | ios::out);
    file.write((char*)&numberOfStudents,sizeof(int));
    for(int i=0;i<numberOfStudents;i++){
        file.write((char*)&students[i],sizeof(Student));
        for(int j=0;j<students[i].jobsNum;j++){
            file.write((char*)&students[i].job[j],sizeof(Job));
        }
    }
    file.close();
    return true;
}
