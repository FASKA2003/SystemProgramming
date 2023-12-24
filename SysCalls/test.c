#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  cpu_set_t cpuset;
  uint num_cpu = sysconf(_SC_NPROCESSORS_ONLN);
  CPU_ZERO(&cpuset);
  for (int i = 0; i < num_cpu; i++) {
    CPU_SET(i, &cpuset);
  }
  printf("Nombre de CPU dans le set est %d\n", CPU_COUNT(&cpuset));
  return 0;
}
