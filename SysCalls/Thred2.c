#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *fct_thread(void *args);

int main(int argc, char *argv[]) {
  pthread_t threadA, threadB;
  char argA = 'A';
  char argB = 'B';

  pthread_create(&threadA, NULL, fct_thread, (void *)argA);
  pthread_create(&threadB, NULL, fct_thread, (void *)argB);

  pthread_join(threadA, NULL);
  pthread_join(threadB, NULL);

  printf("Main thread is done\n");
  return 0;
}

void *fct_thread(void *args) {
  char threadName = (char)args;
  printf("Thread %c is running\n", threadName);
  if (threadName == 'B') {
    pthread_t thread_c;
    char argC = 'C';
    pthread_create(&thread_c, NULL, fct_thread, (void *)argC);
    pthread_join(thread_c, NULL);
  }
  printf("Thread %c is done\n", threadName);
  return NULL;
}
