#include <iostream>
#include <fstream>
#include <string>

#define SLASH "/"

#define DEBUG 0

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
	int numberOfStudents=3;
	struct Student *students = new Student[numberOfStudents];
	for(int i=0;i<numberOfStudents;i++){
		cout << "Student " << i << endl << "FirstName:  ";
		cin >> students[i].firstName;
		cout << "lastName:  ";
		cin >> students[i].lastName;
		cout << "JobsNum:  ";
		cin >> students[i].jobsNum;
		students[i].job=new Job[students[i].jobsNum];
		for(int j=0;j<students[i].jobsNum;j++){
			cout << "Job " << j << endl << "Name:  ";
			cin >> students[i].job[j].name;
			cout << "Desc:  ";
			cin >> students[i].job[j].desc;
			cout << "Job status:  ";
			cin >> students[i].job[j].jobStatus;
		}
	}
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
