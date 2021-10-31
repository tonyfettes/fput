tup.include('tupco/unit.lua')

local gcc = toolchains.gcc
local static_library = gcc.recipes.static_library
local executable = gcc.recipes.executable
local object = gcc.recipes.object
local profiles = gcc.profiles

fput_incdir = 'src'

fput = unit {
  toolchain = gcc,
  recipes = {
    ["libfput.a"] = static_library {
      sources = { 'src/fput.c' },
    },
    ["fput.o"] = object {
      sources = { 'src/fput.c' },
    }
  },
  profiles = {
    profiles.release
  },
}

test = unit {
  toolchain = gcc,
  recipes = {
    ["fput"] = executable {
      dependencies = {
        fput.recipes["libfput.a"]
      },
      sources = { 'test/src/fput.c', 'test/src/main.c' },
      include_dirs = { fput_incdir },
    },
    ["fprintf"] = executable {
      sources = { 'test/src/fprintf.c', 'test/src/main.c' },
      include_dirs = { fput_incdir },
    },
  },
  profiles = {
    profiles.debug,
    profiles.release
  }
}
