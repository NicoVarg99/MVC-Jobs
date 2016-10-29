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
