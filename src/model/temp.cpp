#include <iostream>
#include <fstream>
#include <string>

#define SLASH "/"

#define DEBUG 1

using namespace std;


struct Job{
	char name[50];
	char desc[1000];
	int jobStatus;
	        //0 - No job assigned
                //10 - Job assigned
                //20 - Job started
                //30 - Job completed
};

struct Student{
	char firstName[50];
	char lastName[50];
	int jobsNum; //Number of jobs of the Student
	struct Job *job;
};

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
            myfile.write((char *)0, sizeof(int)); // setto il numero di studenti a 0
            myfile.close();
            return true;
        }
        return false;
    }
    return true;
}

int main(){
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
        }
        return students;
    }
    else
    {
        if(DEBUG)
            cout << "Unable to open file:  " << fileName << endl;
        return NULL;
    }
    return 42;
}
