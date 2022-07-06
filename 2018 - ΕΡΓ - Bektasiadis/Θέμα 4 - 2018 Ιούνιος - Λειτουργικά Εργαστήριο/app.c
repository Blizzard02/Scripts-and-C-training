#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

volatile sig_atomic_t current = 10;

void signal_handler(int signal){
  switch(signal){
    case SIGINT:  current++; break;
    case SIGTSTP: current--; break;
  }
  system("clear");
  printf("Current Value: %d\n", current);
}

int main(int argc, char* argv[]){
  printf("Current Value: %d\n", current);

  signal(SIGINT, &signal_handler);
  signal(SIGTSTP, &signal_handler);

  while(current);
  
  return 0;
}
