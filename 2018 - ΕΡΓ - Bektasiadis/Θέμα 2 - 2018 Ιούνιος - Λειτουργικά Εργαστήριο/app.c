#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]){

  pid_t pid1, pid2;

  if(!(pid1 = fork())){
    printf("PID: %d, PPID: %d\n", getpid(), getppid());
    execlp("ls", "ls", "-l", argv[1], NULL);
  }else{
    if(!(pid2 = fork())){
      printf("PID: %d, PPID: %d\n", getpid(), getppid());
      execlp("pwd", "pwd", NULL);
    }
    else
      wait(NULL);
  }

  return 0;
}
