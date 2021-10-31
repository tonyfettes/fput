#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include "print.h"

int print(FILE *stream) {
  fprintf(stderr, "fprintf: start\n");
  clock_t start = clock();
  for (int i = 0; i < PRINT_SIZE; i++) {
    int a = rand();
    char b = rand() % CHAR_MAX;
    int c = rand();
    int d = rand();
    fprintf(stream, "%d:%c:%d:%d\n", a, b, c, d);
  }
  clock_t stop = clock();
  fprintf(stderr, "fprintf: %lf s\n", (double)(stop - start) / CLOCKS_PER_SEC);
  return 0;
}
