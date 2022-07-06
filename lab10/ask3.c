#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t counter = 1;
static void handler(int sig) 
{
    printf ("\nCaught signal(%d) %d times.\n", sig, counter); 
    counter++;
}

int main (int argc, char *argv[]) 
{
    struct sigaction act = { {0} }; 
    act.sa_handler = &handler;
    sigaction(SIGINT, &act, NULL);
    while (counter != 5) {}
    return 0; 
}