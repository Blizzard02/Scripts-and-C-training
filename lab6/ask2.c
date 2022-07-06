#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int i;

    for(i=0; i<2; i++)
    {
        pid = fork();

        if(pid == 0)
        {
            printf("my pid is %d\nmy parent's pid is %d\n", getpid(), getppid());    
            exit(0);   
        }
    }

    for(i=0; i<2; i++)
    {
        waitpid(-1, NULL, 0);
    }


    return 0;
}