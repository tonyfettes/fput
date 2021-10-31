project('fput', 'c')

fput_lib = static_library('fput', ['src/fput.c'])
fput_inc = include_directories('src')
fput = declare_dependency(link_with: fput_lib, include_directories: fput_inc)

subdir('test')
