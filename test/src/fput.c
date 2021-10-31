#include <fput.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include "print.h"

int print(FILE *stream) {
  fprintf(stderr, "fput: start\n");
  clock_t start = clock();
  for (int i = 0; i < PRINT_SIZE; i++) {
    fput(stream, 
      (i, rand()),
      (c, ':'),
      (c, rand() % CHAR_MAX),
      (c, ':'),
      (i, rand()),
      (c, ':'),
      (i, rand()),
      (c, '\n')
    );
  }
  clock_t stop = clock();
  fprintf(stderr, "fput: %lf s\n", (double)(stop - start) / CLOCKS_PER_SEC);
  return 0;
}

