#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <arg1> <arg2> ... <argN>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Obtenir le nombre de processeurs disponibles
  int num_processors = sysconf(_SC_NPROCESSORS_ONLN);
  if (num_processors == -1) {
    perror("Erreur lors de l'obtention du nombre de processeurs");
    exit(EXIT_FAILURE);
  }

  printf("Nombre de processeurs disponibles : %d\n", num_processors);

  for (int i = 1; i < argc; ++i) {
    pid_t pid = fork();

    if (pid == -1) {
      perror("Erreur lors de la création du processus");
      exit(EXIT_FAILURE);
    } else if (pid == 0) {
      // Processus enfant

      // Affinité de processeur
      cpu_set_t cpuset;
      CPU_ZERO(&cpuset);
      CPU_SET(i % num_processors, &cpuset);

      if (sched_setaffinity(0, sizeof(cpu_set_t), &cpuset) == -1) {
        perror("Erreur lors de la modification de l'affinité de processeur");
        exit(EXIT_FAILURE);
      }

      printf("Processus %d, PID %d, Affinité CPU %d : %s\n", i, getpid(),
             i % num_processors, argv[i]);
      exit(EXIT_SUCCESS);
    } else {
      // Processus parent
      waitpid(pid, NULL, 0);
    }
  }

  return EXIT_SUCCESS;
}
