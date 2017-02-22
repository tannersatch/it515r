## IT 515R - Scientific Computing - Phase 3
### Tanner Satchwell
### tannersatch@gmail.com

## Files

solver.cpp - main phase file
binary.cpp - a program to generate binary test input
CMakeLists.txt - cmake file

## Phase 3 Instructions

### Load the necessary modules

module load cmake

module unload compiler_gnu/4.9.2
module load compiler_gnu/5/3

module unload compiler_intel/14.0.2
module load compiler_intel/2017

module load llvm/3.9
module load compiler_cland/3.5.0

### Prepare to build the program

mkdir build
cd build

### Run one of the following cmake

CXX=g++; cmake ..
CXX=icpc; cmake ..
CXX=clang++; cmake ..

### Build your executables

make

### Run solver

./solver < [BINARY_INPUT] > [BINARY_OUTPUT]

### Clean up

make clean
