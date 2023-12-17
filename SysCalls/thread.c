#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern int errno;

void *f1(void *);
void *f2(void *);

int main(int argc, char *argv[]) {
  pthread_t tid1, tid2;
  int counterA = atoi(argv[1]);
  int counterO = atoi(argv[2]);
  pthread_create(&tid1, NULL, f1, (void *)&counterA);
  pthread_create(&tid2, NULL, f2, (void *)&counterO);

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  printf("\n");
  return 0;
}

void *f1(void *arg) {
  int counter = *(int *)arg;
  for (int i = 0; i < 1000; i++) {
    fprintf(stderr, "%c", 'A');
  }
  pthread_exit(NULL);
}
void *f2(void *arg) {
  int counter = *(int *)arg;
  for (int i = 0; i < counter; i++) {
    fprintf(stderr, "%c", '0');
  }
  pthread_exit(NULL);
}
