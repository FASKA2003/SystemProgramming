#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *fct_thread(void *args) {
  char threadName = (char)args;
  char C_Name = 'C';
  printf("Thread %c is running.\n", threadName);
  if (threadName == 'B') {
    pthread_t threadC;
    pthread_create(&threadC, NULL, fct_thread, (void *)C_Name);
    pthread_join(threadC, NULL);
  }
  printf("Thread %c is done.\n", threadName);
  return NULL;
}

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
