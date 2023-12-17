#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int size;
int N;
void validateArgs(int argc, char *argv[]);
void generateVecor(double *vect, u_int length);
void seq_moyenne(double *vectIn, double *vectOut, u_int len);
void printResult(double *vect, u_int len);

int main(int argc, char *argv[]) {
  validateArgs(argc, argv);
  u_int length = atoi(argv[1]);
  double *InVector = calloc(length, sizeof(double));
  double *OutVector = calloc(length, sizeof(double));
  double table[10] = {50, 20, 15, 21, 45, 55, 23, 11, 29, 30};
  // generateVecor(InVector, length);
  seq_moyenne(table, OutVector, length);
  printResult(OutVector, length);
  return EXIT_SUCCESS;
}

void validateArgs(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Invalid number of args.");
  }
  if (sscanf(argv[1], "%d", &N) == 0) {
    fprintf(stderr, "Invalid number of elements.");
  }
}

void generateVecor(double *vect, u_int length) {
  double val;
  for (int i = 0; i < length; i++) {
    *(vect + i) = (double)rand();
  }
}

void seq_moyenne(double *vectIn, double *vectOut, u_int len) {
  for (int i = 0; i < len; i++) {
    double sum = 0;
    for (int j = 0; j < len; j++) {
      if (i >= j) {
        sum += vectIn[i - j];
      } else {
        break;
      }
    }
    vectOut[i] = (double)sum / len;
  }
}

void printResult(double *OutVector, u_int len) {
  for (u_int i = 0; i < len; i++) {
    printf("Y[%d] = %lf.\n", i, OutVector[i]);
  }
}
