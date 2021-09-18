local function merge(first, last)
  local result = {}
  for _, element in ipairs(first) do
    table.insert(result, element)
  end
  for _, element in ipairs(last) do
    table.insert(result, element)
  end
  return result
end

local source_dir = 'src'
local test_dir = 'test'
local lib_sources = tup.glob(source_dir .. '/*.c')
local test_sources = tup.glob(test_dir .. '/*.c')
local sources = merge(lib_sources, test_sources);
local compiler = 'gcc'
local build_dir = 'build'
local flags = {
  '-g',
  '-std=c99',
  '-Wall',
  '-Wextra',
  '-Wconversion',
  '-I',
  source_dir,
}

local function compile (args)
  -- args = {
  --   compiler = 'g++',
  --   flags = { '-g', ... },
  --   inputs = { 'example.cpp', ... },
  --   output = { 'example.o' }
  -- }
  local command = {
    args.compiler,
    table.concat(args.flags, ' '),
    '-c',
    table.concat(args.inputs, ' '),
    '-o',
    args.output,
  }
  tup.definerule {
    inputs = args.inputs,
    command = table.concat(command, ' ');
    outputs = {args.output},
  }
end

local function link (args)
  -- args = {
  --   linker = 'g++',
  --   flags = { '-pg', ... },
  --   inputs = { 'example.o', ... },
  --   output = 'example'
  -- }
  local command = {
    args.linker,
    table.concat(args.flags, ' '),
    table.concat(args.inputs, ' '),
    '-o',
    args.output,
  }
  tup.definerule {
    inputs = args.inputs,
    command = table.concat(command, ' ');
    outputs = {args.output},
  }
end

local function compile_dep(args)
  -- args = {
  --   name = 'dep.o',
  --   sources = { 'lib.c', ... },
  -- }
  local objects = {}
  for _, source in ipairs(args.sources) do
    local object = build_dir .. '/' .. tup.base(source) .. '.o'
    table.insert(objects, object)
    compile {
      compiler = compiler,
      flags = flags,
      inputs = {source},
      output = object,
    }
  end
  return objects
end

local function compile_bin(args)
  -- args = {
  --   name = 'example',
  --   sources = { 'main.cpp' },
  --   deps = { 'dep.o' },
  --   dir = 'build',
  -- }
  local objects = {}
  for _, source in ipairs(args.sources) do
    local object = args.dir .. '/' .. tup.base(source) .. '.o'
    table.insert(objects, object)
    compile {
      compiler = compiler,
      flags = flags,
      inputs = {source},
      output = object,
    }
  end
  objects = merge(objects, args.deps);
  link {
    linker = compiler,
    flags = flags,
    inputs = objects,
    output = args.dir .. '/' .. args.name,
  }
end

compile_bin {
  name = 'fputi_test',
  sources = test_sources,
  deps = compile_dep {
      name = 'fput.o',
      sources = lib_sources,
  },
  dir = 'build/test',
}
