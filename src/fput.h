// vim: ft=c
#include <stdio.h>

int fputi(int source, FILE *restrict stream);

#define fmt(type, arg) type, arg

#define __make_fput_call(fn, stream, ...) \
  __make_fput_name(fn, __VA_ARGS__, \
      16, 15, 14, 13, 12, 11, 10, 9, \
      8, 7, 6, 5, 4, 3, 2, 1, \
      0)(stream, __VA_ARGS__)
#define __make_fput_name(fn, \
    fmt0, fmt1, fmt2, fmt3, fmt4, fmt5, fmt6, fmt7, \
    fmt8, fmt9, fmt10, fmt11, fmt12, fmt13, fmt14, fmt15, \
    n, ...) fn##n
#define fput(stream, ...) __make_fput_call(fput, stream, __VA_ARGS__)
#define fput0(stream)
#define fput_direct(stream, type, arg) fput##type(arg, stream)
#define fput_unpack(stream, fmt0) fput_direct(stream, fmt0)
#define fput1(stream, fmt0) fput_unpack(stream, fmt fmt0)
#define fput2(stream, fmt0, ...)  fput1(stream, fmt0); fput1(stream, __VA_ARGS__)
#define fput3(stream, fmt0, ...)  fput1(stream, fmt0); fput2(stream, __VA_ARGS__)
#define fput4(stream, fmt0, ...)  fput1(stream, fmt0); fput3(stream, __VA_ARGS__)
#define fput5(stream, fmt0, ...)  fput1(stream, fmt0); fput4(stream, __VA_ARGS__)
#define fput6(stream, fmt0, ...)  fput1(stream, fmt0); fput5(stream, __VA_ARGS__)
#define fput7(stream, fmt0, ...)  fput1(stream, fmt0); fput6(stream, __VA_ARGS__)
#define fput8(stream, fmt0, ...)  fput1(stream, fmt0); fput7(stream, __VA_ARGS__)
#define fput9(stream, fmt0, ...)  fput1(stream, fmt0); fput8(stream, __VA_ARGS__)
#define fput10(stream, fmt0, ...) fput1(stream, fmt0); fput9(stream, __VA_ARGS__)
#define fput11(stream, fmt0, ...) fput1(stream, fmt0); fput10(stream, __VA_ARGS__)
#define fput12(stream, fmt0, ...) fput1(stream, fmt0); fput11(stream, __VA_ARGS__)
#define fput13(stream, fmt0, ...) fput1(stream, fmt0); fput12(stream, __VA_ARGS__)
#define fput14(stream, fmt0, ...) fput1(stream, fmt0); fput13(stream, __VA_ARGS__)
#define fput15(stream, fmt0, ...) fput1(stream, fmt0); fput14(stream, __VA_ARGS__)
#define fput16(stream, fmt0, ...) fput1(stream, fmt0); fput15(stream, __VA_ARGS__)

#define put(...) fput(stdout, __VA_ARGS__)
