tup.include('tupco/unit.lua')

local gcc = toolchains.gcc
local static_library = gcc.recipes.static_library
local executable = gcc.recipes.executable
local object = gcc.recipes.object
local profiles = gcc.profiles

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

fput:build()
