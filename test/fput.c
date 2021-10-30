#include "fput.h"
#include <stdlib.h>
#include <limits.h>

int main(void) {
  srand(1);
  for (int i = 0; i < 100000000; i++) {
    put(
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
  return 0;
}
