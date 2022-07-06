#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int argc, char *argv []) 
{ 
    pid_t pid; 
    pid = fork();
    
    if (pid == 0) 
    { 
        execlp("ls", "ls", NULL);
        printf ("execlp error\n");
        exit(1);
    }

    waitpid(-1, NULL, 0);

    return 0;
}