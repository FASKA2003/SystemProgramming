#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char *historysize = getenv("HISTSIZE");
  printf("Original value of HISTSIZE : %s\n", historysize);

  putenv("HISTSIZE=500");
  historysize = getenv("HISTSIZE");
  printf("Changed value of HISTSIZE after getenv : %s\n", historysize);

  setenv("HISTSIZE", "300", 1);
  printf("Changed value of HISTSIZE after setenv : %s\n", historysize);
  return 0;
}
