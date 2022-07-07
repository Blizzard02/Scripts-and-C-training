#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int count = 0;

void signalHandler(int sig){

    printf("count = %d\n", count);
    exit(0);
}


int main(){

    int i, signum; // for loop iterator
    pid_t pid; // pids of child processes

    signal(SIGINT, signalHandler);

    // Fork 3 child processes
    pid = fork();
    if(!pid){ // If child process
        while(1){
            count++;
        }
    }else if(pid > 0){

        // Parent process only
        while(1){
            count++;
        }
    }

}
