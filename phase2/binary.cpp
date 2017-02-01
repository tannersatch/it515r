/**
 * IT 515R - Scientific Computing - Phase 2 Binary Test Input
 * @author Tanner Satchwell tannersatch@gmail.com
**/

#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

void initializeGrid(uint32_t r, uint32_t c, float ** grid);
bool isStable(uint32_t r, uint32_t c, float e, float ** grid);
void recalcGrid(uint32_t r, uint32_t c, float ** grid, float ** tmp);
void printGrid(uint32_t r, uint32_t c, float ** grid);
void cleanUp(uint32_t r, float ** grid);

int main() {
	// declare vars
	uint32_t itr = 0;
	float epsilon = 0.1;
	uint32_t rows = 1024;
	uint32_t cols = 1024;

	float ** grid1;

	// Allocate memory
	grid1 = new float * [rows];
	for (int i = 0; i < rows; ++i) {
		grid1[i] = new float [cols];
	}

	// initialize grid
	initializeGrid(rows, cols, grid1);

	// output binary
	cout.write(reinterpret_cast<char const *>(&itr), sizeof(uint32_t));
	cout.write(reinterpret_cast<char const *>(&epsilon), sizeof(float));
	cout.write(reinterpret_cast<char const *>(&rows), sizeof(uint32_t));
	cout.write(reinterpret_cast<char const *>(&cols), sizeof(uint32_t));
	printGrid(rows, cols, grid1);

	// De-allocate memory
	cleanUp(rows, grid1);

	// Print out number of iterations
	cout << itr << endl;

	return 0;
}

/**
 * Initialize grid
 * @param r
 *	The number of rows in the 2D grid
 * @param c
 *	The number of columns in the 2D grid
 * @param grid
 *	Dereferenced 2D grid to be initialized
**/
void initializeGrid(uint32_t r, uint32_t c, float ** grid) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (i == 0 || j == 0 || (i == r-1) || (j == c-1)) {
				grid[i][j] = 0;
			} else {
				grid[i][j] = 50;
			}
		}
	}
}

/**
 * Print grid
 * @param r
 *	The number of rows in the 2D grid
 * @param c
 *	The number of columns in the 2D grid
 * @param grid
 *	Dereferenced 2D grid
**/
void printGrid(uint32_t r, uint32_t c, float ** grid) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout.write(reinterpret_cast<char const *>(&grid[i][j]), sizeof(float));
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
void cleanUp(uint32_t r, float ** grid) {
	for (int i = 0; i < r; ++i) {
		delete [] grid[i];
	}
	delete [] grid;
}




