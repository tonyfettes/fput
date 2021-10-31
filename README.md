# `fput`

A format library in C.

## Usage

```c
struct complex_t {
  double real;
  double imag;
};
int fput_complex(const complex_t *complex, FILE *stream) {
  fprintf(stream, "%lf + %lf i", real, imag);
}

int main() {
  complex_t a = { 1, -1 }
  fput(stdout, (s, "Hello, world\n"), (complex, a), (c, '\n'));
  // stdout:
  // Hello, world
  // 1 + -1 i
  return 0;
}
```

## Credits

[fmt](https://github.com/fmtlib/fmt)
