/*Να γραφεί πρόγραμμα σε C που θα δημιουργεί δύο νέα processes.
Τα νέα processes θα πρέπει να τυπώνουν το καθένα το δικό του
process id και το process id του process που τα δημιούργησε (το
parent process id που θα τυπώνεται από τα 2 νέα processes θα
πρέπει να είναι το ίδιο)*/

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
