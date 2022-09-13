#include "shell.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

void execute(char* const args[])
{
    int i;
    pid_t pid = 0;
    int status;
    printf("*** Entered:");
    for (i = 0; args[i] != NULL; i++)
        printf(" %s", args[i]);
    printf(" (%d words)\n", i);
    pid = fork();
    if (pid == 0) {
	char temp[] = "/bin/";
	char *result = malloc(strlen(temp) + strlen(args[0]) + 1);
	strcpy(result,temp);
	strcat(result,args[0]);
	if (execv(result,args) == -1) {
		printf("*** Command not found: %s\n", args[0]);
		}
	exit(1);
	}
    if (pid > 0) {
	pid = wait(&status);
   	if (WIFEXITED(status)) {
		int statVal = WEXITSTATUS(status);
		if (statVal != 0) {
			printf("*** Child exited with %d\n",statVal);
			}
		else {
			printf("*** Child exited sucessfully\n");
			}
		}
    	if (WIFSIGNALED(status)) {
		printf("*** Child exited with %d\n", WTERMSIG(status));
		}
    	}
    if (pid < 0) {
	perror("In fork():");
	}
}
