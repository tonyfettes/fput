#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
  srand(1);
  for (int i = 0; i < 100000000; i++) {
    printf("%d:%c:%d:%d\n", rand(), rand() % CHAR_MAX, rand(), rand());
  }
  return 0;
}
