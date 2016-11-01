#include "model.h"

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

int model_countStudents(){
    if(!model_checkDB()){ // se il file non esiste o non riesce ad aprirlo
	    if(model_createDB())
		    return 0;
        return -1;
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
        return n;
    }
    return -1;
}

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
        int n=model_countStudents();
        Student * students;
        students = new Student [n];
        file.seekg(sizeof(int),file.beg); //sposta il cursore dopo l'intero che contiene il numero di studenti
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

bool model_addStudent(struct Student student){
    int n = model_countStudents();
    if(n==-1) return false;
    Student *students = model_loadStudents();
    if(students==NULL) return false;
    Student *newStudents = new Student [n+1];
    for (int i=0;i<n;i++)
        newStudents[i]=students[i];
    newStudents[n]=student;
    n++;
    if(model_writeStdents(newStudents,n)){
        view_printDebug("Aggiunto correttamente");
        return true;
    }
    view_printDebug("Errore nell'aggiunta");
    return false;
}

bool model_removeStudent(int numberOfTheStudent){
    int n=model_countStudents();
    if(n==-1) return false;
    Student *students = model_loadStudents();
    if(students==NULL) return false;
    n--;
    for(int i=numberOfTheStudent;i<n;i++)
        students[i]=students[i+1];
    if(model_writeStdents(students,n)){
        view_printDebug("Studente eliminato correttamente");
        return true;
    }
    return false;
}
