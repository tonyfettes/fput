fput_test = executable(
  'fput_test',
  ['src/main.c', 'src/fput.c', 'src/print.h'],
  dependencies: [fput]
)

fprintf_test = executable(
  'fprintf_test',
  ['src/main.c', 'src/fprintf.c', 'src/print.h'],
  dependencies: [fput]
)

diff = find_program('diff', required: true)

test('test/fput', fput_test, args: ['fput.out'])
test('test/fprintf', fprintf_test, args: ['fprintf.out'])
