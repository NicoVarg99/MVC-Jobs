#include <cstdio>
#include <cstdlib>
#define DEBUG 1
#define LINEA "-------------------------------------------------------------------------------\n\n"
#ifdef __linux__
    #define clearscreen system("clear");
    #include "conio.cpp"
#elif _WIN32
    #include <conio.h>
    #define clearscreen system("CLS");
#endif

void controller_start();
int mainmenu();
void printError(int e);
void printDebug(char* dastampare);

void controller_start()
{
    int c; //variable used for storing the user's choice once mainmenu has completed its function.
    c=mainmenu(); //gets c's value from mainmenu.
    printf("%d",c);

		//view_printPrompt();
		//c=view_xxx();

		switch(c){
			//List all the students with their current job
			case 1:
				//TODO CARLO
				//NOTE: DO NOT EDIT THIS FILE

				//check if file exists
				//if exists
						//list all students with their current job
						//
						//while(model_isDataAvailable){
						//	view_printStudentList(model_getData("firstName"),model_getData("lastName"),model_getData("currentJob"));
						//	model_pop();
						//}
						//NOTE: Do not print anything. That is view's job
						//      Ask Mirco for adequate functions if needed.
				//if not
						//print an error message
						//view_error("Data file not found.");
				break;

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
				//Unless nothing supernatural happens, a case that's anything else than 1-6 will never happen.
				break;
    }

}


int mainmenu(){
	int c=1,s=1; //c now takes the first key input from buffer, avoiding the trouble of having the
	// user press enter. s is the variable used to show the current selection to the user.

	while(1){
        printf(LINEA"\t\t\t\tMVC - Jobs");
        //printDebug("Hello!");
        //printError(3);
        printf("\n\n"LINEA);
        printf("Si scelga l'azione da compiere:\n\n");
        if(s==1) printf("<1>");
        else printf(" 1 ");
        printf(" - Stampare una lista di tutti gli studenti con i rispettivi lavori;\n");
        if(s==2) printf("<2>");
        else printf(" 2 ");
        printf(" - Aggiungere un nuovo studente alla lista;\n");
        if(s==3) printf("<3>");
        else printf(" 3 ");
        printf(" - Rimuovere uno degli studenti dalla lista;\n");
        if(s==4) printf("<4>");
        else printf(" 4 ");
        printf(" - Modificare gli attributi di uno degli studenti sulla lista;\n");
        if(s==5) printf("<5>");
        else printf(" 5 ");
        printf(" - Assegna/modifica un lavoro di uno studente;\n");
        if(s==6) printf("<6>");
        else printf(" 6 ");
        printf(" - Termina il programma;\n");
        printf("\n\t\t     [TASTI W-S PER SCEGLIERE L'OPZIONE]\n\n");
        c=getch();
        if(c==115||c==83) s++;
        if(c==119||c==87) s--;
        if(c==13) return s;
        if(s==7) s=1;
        if(s==0) s=6;
        clearscreen;
        //printf("%d",c);
        continue;
    }
}

void printError(int e){

    switch (e){

    case 1:
        printf("ERRORE: Esempio di errore.");
        break;

    case 2:
        printf("ERRORE: Altro Esempio di errore.");
        break;

    case 3:
        printf("ERRORE: E' FINITO IL CAFFE'! MORIREMO TUTTIIII!!!");
        break;
    }

    //All of the potential errors will be stored here. When you need to print out an error, simply call the print error function with
    //The proper input number.
}

void printDebug(char* dastampare){
printf("Debug: %s\n",dastampare);
}
