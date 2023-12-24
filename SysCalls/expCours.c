#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  pid_t pid;
  for (int i = 0; i < 5; i++) {
    pid = fork();
    if (pid != 0) {
      printf("%d\n", pid);
      wait(NULL);
    }
  }
  return 0;
}
