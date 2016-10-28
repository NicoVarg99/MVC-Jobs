struct Job{
	char name[50];
	char desc[1000];
	int status;
};

struct Student{
	char firstName[50];
	char lastName[50];
	int isBusy;
	struct Job job;
};
