#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sighandler(int signal){
     if(signal == SIGINT){
        printf("This program has stopped due to SIGINT\n");
        exit(1);
     }
     if(signal == SIGUSR1){
       printf("Parent PID : %d\n", getppid());
       printf("Continuing program...\n");
     }
  }

int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  while(1){
     printf("Process' PID: %d\n", getpid());
     sleep(1);
  }
  return 0;
}
