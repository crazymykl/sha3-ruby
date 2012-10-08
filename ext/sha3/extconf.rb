require "mkmf"

find_header "KeccakReferenceAndOptimized/Sources/KeccakNISTInterface.h"

$srcs = ['sha3.c',
  'KeccakReferenceAndOptimized/Sources/KeccakNISTInterface.c',
  'KeccakReferenceAndOptimized/Sources/KeccakSponge.c',
  'KeccakReferenceAndOptimized/Sources/KeccakF-1600-reference.c',
  'KeccakReferenceAndOptimized/Sources/displayIntermediateValues.c']

$objs = ['sha3.o',
  'KeccakReferenceAndOptimized/Sources/KeccakNISTInterface.o',
  'KeccakReferenceAndOptimized/Sources/KeccakSponge.o',
  'KeccakReferenceAndOptimized/Sources/KeccakF-1600-reference.o',
  'KeccakReferenceAndOptimized/Sources/displayIntermediateValues.o']

create_header
create_makefile "sha3"

# This is stupid, but it works
FileUtils.mkdir_p('KeccakReferenceAndOptimized/Sources/')
