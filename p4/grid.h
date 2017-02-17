#ifndef GRID_H
#define GRID_H

#include <iostream>

using std::istream;

configuration readGrid(istream &in, uint32_t &iteration, float &epsilon, uint32_t &rows, uint32_t &cols, float *&data);

#endif