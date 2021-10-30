#include <stdint.h>
#include <memory.h>
#include "fput.h"

#define FMT_POWERS_OF_10(factor)                                             \
  factor * 10, (factor)*100, (factor)*1000, (factor)*10000, (factor)*100000, \
      (factor)*1000000, (factor)*10000000, (factor)*100000000,               \
      (factor)*1000000000

#define clzll(n) __builtin_clzll(n)

int count_digits(uint64_t n) {
  static const uint8_t bsr2log10[] = {
    1,  1,  1,  2,  2,  2,  3,  3,  3,  4,  4,  4,  4,  5,  5,  5,
    6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9,  10, 10, 10,
    10, 11, 11, 11, 12, 12, 12, 13, 13, 13, 13, 14, 14, 14, 15, 15,
    15, 16, 16, 16, 16, 17, 17, 17, 18, 18, 18, 19, 19, 19, 19, 20,
  };
  uint8_t t = bsr2log10[clzll(n | 1) ^ 63];
  static const uint64_t zero_or_powers_of_10[] = {
    0, 0, FMT_POWERS_OF_10(1U), FMT_POWERS_OF_10(1000000000ULL),
    10000000000000000000ULL
  };
  return t - (n < zero_or_powers_of_10[t]);
}

const char* digits2(size_t value) {
  return &"0001020304050607080910111213141516171819"
         "2021222324252627282930313233343536373839"
         "4041424344454647484950515253545556575859"
         "6061626364656667686970717273747576777879"
         "8081828384858687888990919293949596979899"[value * 2];
}

void copy2(char *dst, const char *src) {
  memcpy(dst, src, 2);
}

static char *format_decimal(char *out, uint64_t value, int size) {
  out += size - 1;
  *out = '\0';
  --out;
  while (value >= 100) {
    out -= 2;
    copy2(out, digits2(value % 100));
    value /= 100;
  }
  if (value < 10) {
    *--out = '0' + value;
    return out;
  }
  out -= 2;
  copy2(out, digits2(value));
  return out;
}

int fput_i(int source, FILE *restrict stream) {
  char digits[40];
  char *start = format_decimal(digits, source, 40);
  return fputs(start, stream);
}
