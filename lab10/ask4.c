/*Να γραφεί πρόγραμμα σε C που θα δημιουργεί ένα νέο process.
To process θα τρέχει συνεχώς και τυπώνει κάθε 2 δευτερόλεπτα
”Luke, I Am Your Father””. Θα πρέπει να υλοποιήσετε έναν
signal handler που θα κάνει pause και continue το process που
δημιουργήθηκε. Θα πρέπει να τυπώνονται κατάλληλα μηνύματα
κατά την αλλαγή κατάστασης του process.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t paused = 0;
int child_pid;

static void handler(int sig) 
{
    if(paused == 0)
    {
        printf("Pausing child process\n");
        paused = 1;
        kill(child_pid,SIGSTOP);
    }
    else if(paused == 1)
    {
        printf("Resuming child process\n");
        paused = 0;
        kill(child_pid,SIGCONT);
    }
}

int main(int argc, char* argv[])
{
    pid_t pid;

    pid = fork();

    if(pid == 0)
    {
        struct sigaction act = { {0} };
	
	    act.sa_handler = SIG_IGN; // ignore signal
	    sigaction(SIGINT,&act,NULL);

        while(1)
        {
            printf("Luke, I Am Your Father\n");
            sleep(2);
        }
    }
    else
    {
        struct sigaction act = { {0} };
	
	    act.sa_handler = &handler; // ignore signal
	    sigaction(SIGINT,&act,NULL);

        child_pid = pid;
        
        while(1) {}
    }


    return 0;
}
