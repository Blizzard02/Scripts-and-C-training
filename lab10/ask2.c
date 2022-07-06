/*Να γραφεί πρόγραμμα σε C που θα τρέχει συνεχώς, θα αγνοεί το
signal SIGTSTP και θα τυπώνει ”Received SIGTSTP”.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void handler(int sig)
{
    printf ("\nReceived SIGTSTP\n");
}
int main (int argc, char *argv[]) 
{
    struct sigaction act = { {0} }; 
    act.sa_handler = &handler;
    sigaction(SIGTSTP, &act, NULL);
    while(1) 
    {
        printf("sleep for 5 secs ...\n"); 
        sleep(5);
    }
    return 0; 
}
