#include <cstdio>
#include <cstdlib>
#include <string>
#include "view.h"

#define LINEA "-------------------------------------------------------------------------------\n\n"
#ifdef __linux__
    #define CLEAR "clear"
    #include "conio.cpp"
#elif _WIN32
    #include <conio.h>
    #define CLEAR "CLS"
#endif

//Keys definitions
#define KEY_W		119
#define KEY_CW      87
#define KEY_S		115
#define KEY_CS		83
#define KEY_LINUX_UP		65
#define KEY_LINUX_DOWN	    66
#define KEY_WINDOWS_UP		80
#define KEY_WINDOWS_DOWN	72
#define KEY_LINUX_ENTER	    10
#define KEY_WINDOWS_ENTER   13
#define KEY_LINUX_ESCAPE	27
#define KEY_LINUX_Q		113

void view_printError(const std::string topr){
	printf("ERROR: %s\n",topr.c_str());
}

void view_printMsg(char *topr){
	printf("%s\n",topr);
}

int view_mainMenu(){
	int c=1,s=1; //c now takes the first key input from buffer, avoiding the trouble of having the
	// user press enter. s is the variable used to show the current selection to the user.

	while(1){
        system(CLEAR);
        
	if(DEBUG) printf("%d\n",c);
        
	printf(LINEA "\t\t\t\tMVC - Jobs");
        //printDebug("Hello!");
        //printError(3);
        printf("\n\n" LINEA);
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

	if(DEBUG) printf("%d\n",c);

        if(c==KEY_S||c==KEY_LINUX_DOWN||c==KEY_CS||c==KEY_WINDOWS_UP) s++;
        if(c==KEY_W||c==KEY_LINUX_UP||c==KEY_CW||c==KEY_WINDOWS_DOWN) s--;
        if(c==KEY_WINDOWS_ENTER||c==KEY_LINUX_ENTER)return s;
	if(c==KEY_LINUX_Q)return 6;
        
	//Loop through the menu
        if(s==7) s=1;
        if(s==0) s=6;

        continue;
    }
}

void view_printDebug(const std::string dastampare){
printf("Debug: %s\n",dastampare.c_str());
}

void view_printWaitMessage(){

    int i;
    printf("\nPress [ENTER] to continue...\n\n");
    while(1)
    {
        i=getch();
        if (i==KEY_LINUX_ENTER||i==KEY_WINDOWS_ENTER) break;
    }
    return;
}
