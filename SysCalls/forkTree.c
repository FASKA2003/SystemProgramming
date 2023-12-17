#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

u_int64_t factoriel(u_int8_t n);
void printResult(char *PID, u_int8_t num);

int main(int argc, char *argv[]) {
  pid_t pid;
  int i, n;
  if ((argc == 1) || (sscanf(argv[1], "%d", &n) == 0) || (n < 8)) {
    fprintf(stderr, "Invalid argument.\n");
    return -1;
  }

  for (i = 0; i < 3; i++) {
    pid = fork();
    if (pid == 0) {
      if (i == 0) {
        if (fork() == 0) {
          // printf("Le process F4 avec le pid %d, Le pere est %d.\n", getpid(),
          // getppid());
          printResult("F4", n - 3);
          exit(0);
        }
        // printf("Le process F1 avec le pid %d, Le pere est %d.\n", getpid(),
        // getppid());
        printResult("F1", n);
        exit(0);
      } else if (i == 1) {
        if (fork() == 0) {
          if (fork() == 0) {
            // printf("Le process F8 avec le pid %d, Le pere est %d.\n",
            // getpid(), getppid());
            printResult("F8", n - 7);
            exit(0);
          }
          // printf("Le process F5 avec le pid %d, Le pere est %d.\n", getpid(),
          // getppid());
          printResult("F5", n - 4);
          exit(0);
        }
        // printf("Le process F2 avec le pid %d, Le pere est %d.\n", getpid(),
        // getppid());
        printResult("F2", n - 1);
        exit(0);
      } else if (i == 2) {
        if (fork() == 0) {
          // printf("Le process F6 avec le pid %d, Le pere est %d.\n", getpid(),
          // getppid());
          printResult("F6", n - 5);
          exit(0);
        }
        if (fork() == 0) {
          // printf("Le process F7 avec le pid %d, Le pere est %d.\n", getpid(),
          // getppid());
          printResult("F7", n - 6);
          exit(0);
        }
        // printf("Le process F3 avec le pid %d, Le pere est %d.\n", getpid(),
        // getppid());
        printResult("F3", n - 2);
        exit(0);
      }
    }
  }
  while (wait(NULL) >= 0)
    ;
  return 0;
}

u_int64_t factoriel(u_int8_t n) {
  u_int64_t result = n;
  for (int i = 1; i < n; i++) {
    result *= i;
  }
  return result;
}

void printResult(char *PID, u_int8_t num) {
  printf("%s :Le resutl de calcul de %d!, est %lu.\n", PID, num,
         factoriel(num));
}
