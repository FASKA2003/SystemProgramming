#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

extern char **environ;

int main(int argc, char *argv[]) {
  printf("Environment variable passed are :\n");
  for (int i = 0; environ[i] != NULL; i++) {
    printf("environ[%d] : %s \n", i, environ[i]);
  }
  return 0;
}
