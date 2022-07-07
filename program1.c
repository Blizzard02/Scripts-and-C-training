
#include<stdio.h>
#include<wait.h>
#include<signal.h>
#include<stdlib.h>
#include <unistd.h>
pid_t pid;
int counter = 0;
void handler1(int sig)
{
  counter++;
  printf("counter = %d\n", counter);
  /* Flushes the printed string to stdout */
  fflush(stdout);
 }
void handler2(int sig)
{
  counter += 3;
  printf("counter = %d\n", counter);
  exit(0);
}

int main()
{
  pid_t p;
  int status;
  signal(SIGINT, handler1);
  if ((pid = fork()) == 0)
  {
    signal(SIGINT, handler2);
    while(1) ;
  }
  if ((p = wait(&status)) > 0)
  {
    counter += 4;
    printf("counter = %d\n", counter);
  }
}