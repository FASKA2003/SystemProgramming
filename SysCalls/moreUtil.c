#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 512
#define PAGE_LEN 20

int get_input(FILE *);
void do_more(FILE *file);
int main(int argc, char *argv[]) {
  if (argc == 1) {
    do_more(stdin);
    // fprintf(stdout, "Not enough args!!!\n");
    // exit(0);
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
  int num_of_lines = 0;
  int rv;
  char buffer[MAX_LEN];
  FILE *fp_tty = fopen("/dev//tty", "r");
  while (fgets(buffer, MAX_LEN, file)) {
    fputs(buffer, stdout);
    num_of_lines++;
    if (num_of_lines == PAGE_LEN) {
      rv = get_input(fp_tty);
      if (rv == 0) {
        printf("\033[1A \033[2K \033[1G");
        break;
      } else if (rv == 1) {
        printf("\033[1A \033[2K \033[1G");
        num_of_lines -= PAGE_LEN;
      } else if (rv == 2) {
        printf("\033[1A \033[2K \033[1G");
        num_of_lines -= 1;
      } else {
        break;
      }
    }
  }
}

int get_input(FILE *cmdstream) {
  printf("\033[7m --more--(%%) \033[m");
  int c = getc(cmdstream);
  switch (c) {
  case 'q':
    return 0;
  case ' ':
    return 1;
  case '\n':
    return 2;
  default:
    return 3;
  }
}
