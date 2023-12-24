#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int line = 0;
  char *buffer = malloc(100 * sizeof(char));
  FILE *file = fopen("./matrice1.txt", "r");
  if (file == NULL) {
    fprintf(stderr, "Could not open file");
    return -1;
  }
  char ch;
  while ((ch = fgetc(file)) != EOF) {
    if (ch == '\n') {
      line++;
    }
  }
  printf("%d\n", line);
  int matrix[line][line];
  rewind(file);
  while ((ch = fgetc(file)) != EOF) {
    if ((ch != '\n') && (ch != '\t')) {
      // do nothing
      printf("%c\n", ch);
    }
  }
  return 0;
}
