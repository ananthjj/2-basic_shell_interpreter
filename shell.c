#include "shell.h"
#include <stdio.h>

void execute(char* const args[])
{
    int i;
    printf("*** Entered:");
    for (i = 0; args[i] != NULL; i++)
        printf(" %s", args[i]);
    printf(" (%d words)\n", i);
}
