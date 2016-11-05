#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include "view.h"

#define LINEA "-------------------------------------------------------------------------------\n"
#ifdef __linux__
    #define CLEAR "clear"
    #include "conio.cpp"
#elif _WIN32
    #include <conio.h>
    #define CLEAR "CLS"
#endif

//Keys definitions
#define KEY_W	        	119
#define KEY_CW                  87
#define KEY_S	        	115
#define KEY_CS	           	83
#define KEY_LINUX_UP		65
#define KEY_LINUX_DOWN	        66
#define KEY_WINDOWS_UP		80
#define KEY_WINDOWS_DOWN	72
#define KEY_LINUX_ENTER	        10
#define KEY_WINDOWS_ENTER       13
#define KEY_LINUX_ESCAPE	27
#define KEY_LINUX_Q		113


int view_mainMenu();
void view_printError(const std::string topr);
void view_printDebug(const std::string dastampare);
void view_printMsg(const std::string topr);
void view_printWaitMessage();
bool view_printStudent(struct Student * students);
struct Student view_loadStudent();
int view_workAssignmentSel();

void view_clearScr(){
	system(CLEAR);
}

void view_printError(const std::string topr){
	printf("ERROR: %s\n",topr.c_str());
}

void view_printMsg(const std::string topr){
	printf("%s\n",topr.c_str());
}

int view_mainMenu(){
	int c=1,s=1; //c now takes the first key input from buffer, avoiding the trouble of having the
	// user press enter. s is the variable used to show the current selection to the user.

	while(1){
        system(CLEAR);

	if(DEBUG) printf("%d\n",c);

	printf(LINEA "\n\t\t\t\tMVC - Jobs");
        //printDebug("Hello!");
        //printError(3);
        printf("\n\n" LINEA);
        printf("\nSi scelga l'azione da compiere:\n\n");
        if(s==1) printf("<1>");
        else printf(" 1 ");
        printf(" - Stampare una lista di tutti gli studenti con i rispettivi lavori\n");
        if(s==2) printf("<2>");
        else printf(" 2 ");
        printf(" - Aggiungere un nuovo studente alla lista\n");
        if(s==3) printf("<3>");
        else printf(" 3 ");
        printf(" - Rimuovere uno degli studenti dalla lista\n");
        if(s==4) printf("<4>");
        else printf(" 4 ");
        printf(" - Assegna/modifica un lavoro di uno studente\n");
        if(s==5) printf("<5>");
        else printf(" 5 ");
        printf(" - Termina il programma\n");
        printf("\n\t\t     [TASTI W-S PER SCEGLIERE L'OPZIONE]\n\n");
        c=getch();

	if(DEBUG) printf("%d\n",c);

        if(c==KEY_S||c==KEY_LINUX_DOWN||c==KEY_CS||c==KEY_WINDOWS_UP) s++;
        if(c==KEY_W||c==KEY_LINUX_UP||c==KEY_CW||c==KEY_WINDOWS_DOWN) s--;
        if(c==KEY_WINDOWS_ENTER||c==KEY_LINUX_ENTER)return s;
	if(c==KEY_LINUX_Q)return 5;

	//Loop through the menu
        if(s==6) s=1;
        if(s==0) s=5;

        continue;
    }
}

void view_printDebug(const std::string dastampare){
	if(DEBUG)
		printf("Debug: %s\n",dastampare.c_str());
}

void view_printWaitMessage(){

    int i;
    printf("\nPremi [INVIO] per continuare...\n\n");
    while(1)
    {
        i=getch();
        if (i==KEY_LINUX_ENTER||i==KEY_WINDOWS_ENTER) break;
    }
    return;
}

void view_printStudent(Student student){

    printf(LINEA);
    printf(LINEA);
    printf("Nome:\t\t%s\nCognome:\t%s\n\n",student.firstName,student.lastName);
    if(student.jobsNum)
        printf("\t%d Lavori:\n\n",student.jobsNum);
    else
        printf("\tNessun lavoro assegnato al momento.\n");
    for(int i=0;i<student.jobsNum;i++)
    {
        printf("\t\tLavoro #%d:\n",i+1);
        printf("\t\t%s\n",student.job[i].name);
        printf("\t\t%s\n",student.job[i].desc);
        if(student.job[i].jobStatus==10) printf("\t\tLavoro assegnato, non iniziato.\n");
        if(student.job[i].jobStatus==20) printf("\t\tLavoro assegnato, iniziato.\n");
        if(student.job[i].jobStatus==30) printf("\t\tLavoro completato.\n");
    }

    printf(LINEA);
    printf(LINEA);

}


void view_printStudentList(struct Student *students, int n){

    view_clearScr();
    printf(LINEA);
    printf(LINEA);

    for(int i=0; i<n; i++){
        printf("\n\tStudente #%d\n",i+1);
        printf("\n\tNome:\t\t%s\n\tCognome:\t%s\n",students[i].firstName,students[i].lastName);
        if(students[i].jobsNum)
            printf("\tLavori assegnati: %d\n",students[i].jobsNum);
        else
            printf("\tNessun lavoro assegnato al momento.\n");
        for(int j=0;j<students[i].jobsNum;j++){
            printf("\n\t\tLavoro #%d:\n",j+1);
            printf("\t\t%s\n",students[i].job[j].name);
            printf("\t\t%s\n",students[i].job[j].desc);
            if(students[i].job[j].jobStatus==10) printf("\t\tLavoro assegnato, non iniziato.\n");
            if(students[i].job[j].jobStatus==20) printf("\t\tLavoro assegnato, iniziato.\n");
            if(students[i].job[j].jobStatus==30) printf("\t\tLavoro completato.\n");
        }
        printf("\n");
        printf(LINEA);
    }

    printf(LINEA);

}

void view_printJobListBasic(struct Job *jobs, int n){

    view_clearScr();

    for(int i=0; i<n; i++){
        printf("%d\t",i+1);
        printf("Nome: %s\n Desc:%s\n Status: ",jobs[i].name,jobs[i].desc);
        if(jobs[i].jobStatus==10) printf("Assigned\n");
        if(jobs[i].jobStatus==20) printf("Started\n");
        if(jobs[i].jobStatus==30) printf("Done\n");

	}
}

struct Student view_loadStudent(){

    Student student;
    student.jobsNum=0;
    int e,a;
    printf(LINEA "Nome dello studente:  ");
    cin.getline(student.firstName,sizeof(student.firstName));
    cin.clear();
    if(strlen(student.firstName)==49) while(cin.get()!='\n');
    printf(LINEA "Cognome dello studente:  ");
    cin.getline(student.lastName,sizeof(student.lastName));
    cin.clear();
    if(strlen(student.lastName)==49) while(cin.get()!='\n');
    printf(LINEA "Nome inserito: %s %s\n" LINEA,student.firstName,student.lastName);

    return student;
}

int view_workAssignmentSel(){

	int a=1,b=1;

	while(1){

        printf(LINEA);
		printf("   Si vuole assegnare o modificare un lavoro? \n\n");
		if(b==1) printf("   <1>");
		else printf("    1 ");
		printf(" - Assegnare un lavoro\n");
		if(b==2) printf("   <2>");
		else printf("    2 ");
		printf(" - Modificare un lavoro\n");
		if(b==3) printf("   <3>");
		else printf("    3 ");
		printf(" - Annulla e torna al menu principale\n");
		printf(LINEA);
		a=getch();
		if(a==KEY_S||a==KEY_LINUX_DOWN||a==KEY_CS||a==KEY_WINDOWS_UP) b++;
		if(a==KEY_W||a==KEY_LINUX_UP||a==KEY_CW||a==KEY_WINDOWS_DOWN) b--;
		if(b==4) b=1;
		if(b==0) b=3;
		if(a==KEY_WINDOWS_ENTER||a==KEY_LINUX_ENTER)break;
		if(a==KEY_LINUX_Q)return 6;
        system(CLEAR);
	}
	return b;
}



void view_printJobListBasic(struct Student *student, int n){

    printf(LINEA);
    printf(LINEA);
    printf("Nome:\t\t%s\nCognome:\t%s\n\n",student.firstName,student.lastName);
    if(student.jobsNum)
        printf("\t%d Lavori:\n\n",student.jobsNum);
    else
        printf("\tNessun lavoro assegnato al momento.\n");
    for(int i=0;i<student.jobsNum;i++)
    {
        printf("\t\tLavoro #%d:\n",i+1);
        printf("\t\t%s\n",student.job[i].name);
        printf("\t\t%s\n",student.job[i].desc);
        if(student.job[i].jobStatus==10) printf("\t\tLavoro assegnato, non iniziato.\n");
        if(student.job[i].jobStatus==20) printf("\t\tLavoro assegnato, iniziato.\n");
        if(student.job[i].jobStatus==30) printf("\t\tLavoro completato.\n");
    }

    printf(LINEA);
    printf(LINEA);

}

struct Job view_loadJob(){

    Job job;
	int a;
    printf(" Nome del lavoro:  ");
    cin.getline(job.name,sizeof(job.name));
    cin.clear();
    if(strlen(job.name)==49) while(std::cin.get()!='\n');
    printf(LINEA " Breve descrizione del lavoro:  ");
    cin.getline(job.desc,sizeof(job.desc));
    cin.clear();
    if(strlen(job.desc)==999) while(std::cin.get()!='\n');
    printf(LINEA " Stato del lavoro:\n\n 1=Lavoro assegnato\n\n 2=Lavoro iniziato.\n\n Scelta:  ");
    scanf("%d",&a);
    if(a!=1 && a!=2) do{
		printf("\n Errore: valore non valido.");
		scanf("%d",&a);
	}
	while(a!=1 && a!=2);
	if(a==1) job.jobStatus=10;
    if(a==2) job.jobStatus=20;
    printf(LINEA);

    return job;
}

int view_readInt(){
    int num;
    scanf("%d",&num);
    getchar();
    return num;
}
