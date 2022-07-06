#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main (int argc, char *argv[])
{
    struct sigaction act = { {0} };
    act.sa_handler = SIG_IGN; // ignore signal 
    sigaction(SIGTSTP, &act, NULL);
    while (1) 
    {
        printf("sleep for 5 secs ...\n"); 
        sleep(5);
    }   
return 0; 
}