#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int n = 1;
  while (fork() == 0) {
    if (n >= 5) {
      break;
    } else {
      n++;
    }
  }
  sleep(10);
  printf("%d", n);
  return EXIT_SUCCESS;
}
