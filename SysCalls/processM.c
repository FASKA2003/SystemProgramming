#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

pid_t pid;
pid_t ppid;
int main(int argc, char *argv[]) {
  printf("My pid is : %jd\n", (intmax_t)getpid());
  printf("Parent's pid = %jd\n", (intmax_t)getppid());
  return 0;
}
