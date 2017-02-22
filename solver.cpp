/**
 * IT 515R - Scientific Computing - Phase 1
 * @author Tanner Satchwell tannersatch@gmail.com
**/

#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

void initializeGrid(size_t r, size_t c, float ** grid);
bool isStable(size_t r, size_t c, float ** grid);
void recalcGrid(size_t r, size_t c, float ** grid, float ** tmp);
void printGrid(size_t r, size_t c, float ** grid);
void cleanUp(size_t r, float ** grid);

int main() {
	// declare vars
	int itr = 0;

	size_t rows = 1024;
	size_t cols = 1024;

	// size_t rows;
	// size_t cols;
	// cout << "Input number of rows: ";
	// cin >> rows;
	// cout << "Input number of columns: ";
	// cin >> cols;

	float ** grid1;
	float ** grid2;

	// Allocate memory
	grid1 = new float * [rows];
	grid2 = new float * [rows];
	for (int i = 0; i < rows; ++i) {
		grid1[i] = new float [cols];
		grid2[i] = new float [cols];
	}

	// initialize grid
	initializeGrid(rows, cols, grid1);
	initializeGrid(rows, cols, grid2);

	// check for stability, and recalc as needed
	while (!isStable(rows, cols, grid1) && itr < 200) {
		recalcGrid(rows, cols, grid1, grid2);
		itr ++;
	}

	// printGrid(rows, cols, grid1);

	// De-allocate memory
	cleanUp(rows, grid1);
	cleanUp(rows, grid2);

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
void initializeGrid(size_t r, size_t c, float ** grid) {
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
 * Check to see if the 2D grid is stable.
 * @param r
 *	The number of rows in the 2D grid
 * @param c
 *	The number of columns in the 2D grid
 * @param grid
 *	Dereferenced 2D grid to be evaluated if it is stable
 * @return
 *	True if stable, false if unstable
**/
bool isStable(size_t r, size_t c, float ** grid) {
	float tmp_val;
	for (int i = 1; i < r-1; i++) {
		for (int j = 1; j < c-1; j++) {
			tmp_val = (grid[i-1][j] + grid[i+1][j] + grid[i][j-1] + grid[i][j+1]);
			tmp_val = fabs((tmp_val/4) - grid[i][j]) ;
			if (tmp_val > 0.1) {
				return false;
			}
		}
	}
	return true;
}

/**
 * A single iteration through the 2D grid to recalculated possible stable values.
 * @param r
 *	The number of rows in the 2D grid
 * @param c
 *	The number of columns in the 2D grid
 * @param grid
 *	Dereferenced 2D grid to be recalculated
 * @param tmp
 *	Dereferenced 2D grid to temporarily hold the recalculated values
**/
void recalcGrid(size_t r, size_t c, float ** grid, float ** tmp) {
	for (int i = 1; i < r-1; i++) {
		for (int j = 1; j < c-1; j++) {
			tmp[i][j] = ((grid[i-1][j] + grid[i+1][j] + grid[i][j-1] + grid[i][j+1])/4);
		}
	}

	for (int i = 1; i < r-1; i++) {
		for (int j = 1; j < c-1; j++) {
			grid[i][j] = tmp[i][j];
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
void printGrid(size_t r, size_t c, float ** grid) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

/**
 * De-allocate memory
 * @param r
 *	The number of rows in the 2D grid
 * @param grid
 *	Dereferenced 2D grid
**/
void cleanUp(size_t r, float ** grid) {
	for (int i = 0; i < r; ++i) {
		delete [] grid[i];
	}
	delete [] grid;
}




