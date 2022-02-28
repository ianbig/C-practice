#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid == 0) {
    printf("pid of child %d and group id %d\n", getpid(), getpgid(getpid()));
    sleep(10);
    printf("pid of child %d and group id %d\n", getpid(), getpgid(getpid()));
  }

  printf("pid of parent %d and group id %d\n", getpid(), getpgid(getpid()));

  sleep(5);
  return 0;
}
