#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct {
  double *InVect;
  double *OutVect;
  u_int length;
} Vectors;

int size;
int N;
void validateArgs(int argc, char *argv[]);
void generateVecor(double *vect, u_int length);
void *seq_moyenne(void *args);
void printResult(double *vect, u_int len);

int main(int argc, char *argv[]) {
  validateArgs(argc, argv);
  u_int length = atoi(argv[1]);
  // double *InVector = calloc(length, sizeof(double));
  // double *OutVector = calloc(length, sizeof(double));
  Vectors *NewVects = (Vectors *)calloc(1, sizeof(Vectors));
  NewVects->length = length;
  generateVecor(NewVects->InVect, NewVects->length);

  printResult(NewVects->OutVect, length);
  free(NewVects);
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

void *seq_moyenne(void *args) {
  Vectors *newv = (Vectors *)args;
  int len = newv->length;
  double *vectOut = newv->OutVect;
  double *vectIn = newv->InVect;
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
