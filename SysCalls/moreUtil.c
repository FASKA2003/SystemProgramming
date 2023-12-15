#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 512
void do_more(FILE *file);
int main(int argc, char *argv[]) {
  if (argc == 1) {
    fprintf(stdout, "Not enough args!!!\n");
    exit(0);
  }
  int i = 0;
  FILE *fp;
  while (++i < argc) {
    fp = fopen(argv[i], "r");
    if (fp == NULL) {
      perror("Can't open file\n");
      exit(1);
    }
    do_more(fp);
    fclose(fp);
  }
  return EXIT_SUCCESS;
}

void do_more(FILE *file) {
  char buffer[MAX_LEN];
  while (fgets(buffer, MAX_LEN, file)) {
    fputs(buffer, stdout);
  }
}
