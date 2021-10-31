#include "print.h"
#include <threads.h>
#include <assert.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
  srand(1234);
  FILE *out = fopen(argv[1], "w");
  print(out);
  fclose(out);
  return 0;
}
