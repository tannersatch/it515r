/**
 * IT 515R - Scientific Computing - Phase 4
 * @author Tanner Satchwell tannersatch@gmail.com
**/

#ifndef GRID_H
#define GRID_H

#include <iostream>

using std::istream;

void readGrid(istream &in, uint32_t &iterator, float &epsilon, uint32_t &rows, uint32_t &cols, float **&grid);
void cloneGrid(uint32_t rows, uint32_t cols, float ** source, float **&target);
void copyGrid(uint32_t rows, uint32_t cols, float ** source, float **&target);
void deleteGrid(uint32_t r, float **&grid);

/**
 * Read from stdin and set two grids to be used in calculations
 * @param in
 *	Reference to the istream stdin
 * @param iterator
 *	Reference to the iterator
 * @param epsilon
 *	Reference to the epsilon value
 * @param rows
 *	Reference to the number of rows
 * @param cols
 *	Reference to the number of columns
 * @param grid
 *	Reference to a grid float pointer
**/
void readGrid(istream &in, uint32_t &iterator, float &epsilon, uint32_t &rows, uint32_t &cols, float **&grid) {
	// read in the given binary values
	in.read(reinterpret_cast<char *>(&iterator), sizeof(uint32_t));
	in.read(reinterpret_cast<char *>(&epsilon), sizeof(float));
	in.read(reinterpret_cast<char *>(&rows), sizeof(uint32_t));
	in.read(reinterpret_cast<char *>(&cols), sizeof(uint32_t));

	// allocate memory
	grid = new float * [rows];
	for (uint32_t i = 0; i < rows; i++) {
		grid[i] = new float [cols];
	}

	// initialize the grids to the given grid
	float tmp_val;
	for (uint32_t i = 0; i < rows; i++) {
		for (uint32_t j = 0; j < cols; j++) {
			in.read(reinterpret_cast<char *>(&tmp_val), sizeof(float));
			grid[i][j] = tmp_val;
		}
	}
}

/**
 * Copy grid data to a new grid
 * @param rows
 *	The number of rows in the grid
 * @param cols
 *	The number of cols in the grid
 * @param source
 *	Pointer to the source grid
 * @param target
 *	Reference to the grid to be cloned
**/
void cloneGrid(uint32_t rows, uint32_t cols, float ** source, float **&target) {
	// initialize the grid
	target = new float * [rows];
	for (uint32_t i = 0; i < rows; i++) {
		target[i] = new float [cols];
	}

	copyGrid(rows, cols, source, target);
}

/**
 * Copy grid data to an existing grid
 * @param rows
 *	The number of rows in the grid
 * @param cols
 *	The number of cols in the grid
 * @param source
 *	Pointer to the source grid
 * @param target
 *	Reference to the grid to be copied
**/
void copyGrid(uint32_t rows, uint32_t cols, float ** source, float **&target) {
	// initialize the grids to the given grid
	for (uint32_t i = 0; i < rows; i++) {
		for (uint32_t j = 0; j < cols; j++) {
			target[i][j] = source[i][j];
		}
	}
}

/**
 * De-allocate memory
 * @param r
 *	The number of rows in the 2D grid
 * @param grid
 *	Dereferenced 2D grid
**/
void deleteGrid(uint32_t r, float **&grid) {
	for (int i = 0; i < r; ++i) {
		delete [] grid[i];
	}
	delete [] grid;
}

#endif