#ifndef GRID_H
#define GRID_H

#include <iostream>

using std::istream;

void readGrid(istream &in, uint32_t &iterator, float &epsilon, uint32_t &rows, uint32_t &cols, float **&grid1, float **&grid2);
void cleanUp(uint32_t r, float **&grid);

void readGrid(istream &in, uint32_t &iterator, float &epsilon, uint32_t &rows, uint32_t &cols, float **&grid1, float **&grid2) {
	in.read(reinterpret_cast<char *>(&iterator), sizeof(uint32_t));
	in.read(reinterpret_cast<char *>(&epsilon), sizeof(float));
	in.read(reinterpret_cast<char *>(&rows), sizeof(uint32_t));
	in.read(reinterpret_cast<char *>(&cols), sizeof(uint32_t));

	// allocate memory
	grid1 = new float * [rows];
	grid2 = new float * [rows];
	for (uint32_t i = 0; i < rows; ++i) {
		grid1[i] = new float [cols];
		grid2[i] = new float [cols];
	}

	float tmp_val;
	for (uint32_t i = 0; i < rows; i++) {
		for (uint32_t j = 0; j < cols; j++) {
			in.read(reinterpret_cast<char *>(&tmp_val), sizeof(float));
			grid1[i][j] = tmp_val;
			grid2[i][j] = tmp_val;
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
void cleanUp(uint32_t r, float **&grid) {
	for (int i = 0; i < r; ++i) {
		delete [] grid[i];
	}
	delete [] grid;
}

#endif