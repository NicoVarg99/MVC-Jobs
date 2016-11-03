#include <cstdlib>

void controller_stop(int ret)
{
	exit(ret);
}

void controller_stop()
{
	controller_stop(0);
}

void controller_start()
{
	//Create database if not exists
	if(!model_checkDB())
	{
		view_printMsg((char*)"Creating database...");
		if(!model_createDB())
		{
			//DB creation unsuccessful
			view_printError((char*)"Database creation unsuccessful.");
			controller_stop(1);
		}
		else
		{
			view_printMsg((char*)"Database created successfully.");
		}
	}

	int c;


	//main loop
	while(1){

		c=view_mainMenu();

		if(DEBUG)
			printf("Scelta: %d\n",c);


		//view_printMenu();
		//view_printPrompt();
		//c=view_xxx();

		switch(c){
			//List all the students with their current job
			case 1:
			{
				view_clearScr();

				struct Student * students = model_loadStudents();
				if(students==NULL){
					view_printError("Unable to open database");
				}else{
					//view_printStudentList(students);
					view_printDebug("List the students and their jobs:");
					int numOfStudents=model_countStudents();

					if(numOfStudents==0)
						view_printError("The database is empty!\n");
					else if(numOfStudents==-1)
						view_printError("Unable to open database");
					else{

						printf("%d students in the database\n",numOfStudents);

						view_printStudentList(students,numOfStudents);
						//printf("Student %d/%d - %s\n",i,numOfStudents,students[i].firstName);

					}

				}
				view_printWaitMessage();
				break;
			}
			case 2:
			{
				view_clearScr();

				Student temp=view_loadStudent();

				if(model_addStudent(temp))
					view_printMsg("Studente aggiunto con successo...");
				else
					view_printMsg("Errore sconosciuto nell'aggiunta dello studente alla lista...");

				view_printWaitMessage();

				break;
			}
			case 3:
			{
				view_clearScr();
				WAIT;
				break;
			}
			case 4:
			{
				view_clearScr();
				WAIT;
				break;
			}
			case 5:
			{
				view_clearScr();
				WAIT;
				break;
			}

			//quit
			case 6:
			{
				view_clearScr();
				exit(0);
				break;
			}
			default:
				//TODO MIRCO
				//print an error message
				//view_error("Please enter a number from 1 to 4");
				break;
		}

	}

}
