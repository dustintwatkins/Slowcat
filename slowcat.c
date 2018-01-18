#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char *getenv(const char  *name);

void inputToOutput(int time){
	char str[60];
	while(fgets(str, 60, stdin)){
		fgets(str, 60, stdin);
		printf("%s", str);
		sleep(time);
	}
}

int main(int argc, char* argv[]){
	
	//Check for correct number of arguments input should be 2
	if(argc != 2)
		printf("Incorrect number of arguments!\n");
	
	int sleepTime = 0;
	char* env = getenv("SLOWCAT_SLEEP_TIME");
	if(env != NULL)
		sleepTime = atoi(env);
	else
		sleepTime = 1;
		
	//open file
	FILE *fp;
	char str[60];
	
	//Print the process id	
	fprintf(stderr, "Process Id: %d\n", getpid());

	//check for dash input
	if(*argv[1] == '-'){
		inputToOutput(sleepTime);	
	}

	//opens file for reading
	fp = fopen(argv[1], "r");
	if(fp == NULL){
		perror("Error opening file");
		return(-1);
	}		
	
	while (fgets(str, 60, fp) != NULL){
		//Writes to stdout
		printf("%s", str);
		sleep(sleepTime);
	}

	fclose(fp);

}

