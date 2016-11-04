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
	int numOfStudents;
	struct Student * students;
	int c;

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




	//main loop
	while(1){

		c=view_mainMenu();

		if(DEBUG)
			printf("Scelta: %d\n",c);

		students=model_loadStudents();

		if(students==NULL){
			view_printError("Unable to open database");
		}else{
			//view_printStudentList(students);
			view_printDebug("List the students and their jobs:");
			numOfStudents=model_countStudents();
		}


		//view_printMenu();
		//view_printPrompt();
		//c=view_xxx();

		switch(c){
			//List all the students with their current job
			case 1:
			{
				view_clearScr();

					if(numOfStudents==0)
						view_printError("Il database è vuoto!\n");
					else if(numOfStudents==-1)
						view_printError("Impossibile aprire il database.");
					else{
						//printf("%d students in the database\n",numOfStudents);
						view_printStudentList(students,numOfStudents);
						//printf("Student %d/%d - %s\n",i,numOfStudents,students[i].firstName);
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


                                if(numOfStudents==0){
                                        view_printError("Nessuno studente nel database!");
                                        view_printWaitMessage();
                                        break;
                                }




				view_printStudentListBasic(students,numOfStudents);
				view_printMsg((char*)"Inserisci il numero dello studente da eliminare (0 per annullare)\n");

				int todel=view_readInt();

				if(todel==0)
				{
					view_printMsg((char*)"Annullato.");
					view_printWaitMessage();
					break;
				}
				
				if(todel>numOfStudents)
				{
					view_printError("Lo studente non è nella lista.");
					view_printWaitMessage();
					break;
				}
				
				model_removeStudent(students,todel-1,numOfStudents);

				//remove the student "todel"
				view_printWaitMessage();
				break;
			}
			case 4:
			{
				view_clearScr();

				if(numOfStudents==0){
					view_printError("Nessuno studente nel database!");
					view_printWaitMessage();
					break;
				}


				view_printWaitMessage();
				break;
			}

			//quit
			case 5:
			{
				view_clearScr();
				exit(0);
				break;
			}
			default:
			{
				//TODO MIRCO
				//print an error message
				//view_error("Please enter a number from 1 to 4");
				break;
			}
		}

	}

}
