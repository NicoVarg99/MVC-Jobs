#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

using namespace std;

#include <string>
#include <fstream>
#include <iostream> //provvisorio

bool model_checkFile (const std::string& name);
bool model_checkDB();
bool model_createDB();
struct Student * model_loadStudents();
bool model_writeStdents(struct Student *students, int numberOfStudents);
int model_countStudents();
bool model_addStudent(struct Student student);

#endif
