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
				struct Student * students = model_loadStudents();
				if(students==NULL)
					view_printError("Unable to open database");
				else{
					//view_printStudentList(students);
					view_printDebug("List of the students and their jobs");
				}
				view_printDebug("Press [ENTER] to continue...\n");
				WAIT;
				break;
			}
			case 2:
				break;

			case 3:
				break;

			case 4:
				break;

			case 5:
				break;


			//quit
			case 6:
				exit(0);
				break;

			default:
				//TODO MIRCO
				//print an error message
				//view_error("Please enter a number from 1 to 4");
				break;
		}

	}

}
