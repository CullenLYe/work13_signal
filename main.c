#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sighandler(int signo) {
  if (signo==SIGINT) {
    printf("Program exited due to SIGINT.\n");
    exit(0);
  }
  if (signo==SIGUSR1) {
    printf("Parent Process: %d\n", getppid());
  }
}

int main() {
  signal(SIGINT, sighandler);
  signal (SIGUSR1, sighandler);
  while (1) {
    printf("Current Process: %d\n", getpid());
    sleep(1);
  }
  return 0;
}
