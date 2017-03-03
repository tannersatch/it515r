/**
 * IT 515R - Scientific Computing - Phase 4
 * @author Tanner Satchwell tannersatch@gmail.com
**/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <cstring>
#include <string>
#include <cmath>
#include "grid.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::stringstream;

bool isStable(uint32_t r, uint32_t c, float e, float ** grid);
void recalcGrid(uint32_t r, uint32_t c, float ** grid, float ** tmp);
void printGrid(uint32_t r, uint32_t c, float ** grid);

int main(int argc, char *argv[]) {
	// set up checkpointing
	bool chkpt;
	uint32_t chkpt_interval;
	uint32_t chkpt_counter = 0;
	if (argc == 2) {
		chkpt = true;
		stringstream tmp;
		tmp << argv[1];
		tmp >> chkpt_interval;
	} else {
		chkpt = false;
		chkpt_interval = 0;
	}

	// declare vars
	uint32_t itr;
	float epsilon;
	uint32_t rows;
	uint32_t cols;

	float ** grid1;
	float ** grid2;

	// read grid from cin
	readGrid(cin, itr, epsilon, rows, cols, grid1);
	cloneGrid(rows, cols, grid1, grid2);

	// check for stability, and recalc as needed
	while (!isStable(rows, cols, epsilon, grid1)) {
		recalcGrid(rows, cols, grid1, grid2);
		itr ++;
		chkpt_counter ++;

		// output the checkpoint file
		if (chkpt && (chkpt_counter == chkpt_interval)) {
			chkpt_counter = 0;
			ofstream chkptfile;
			stringstream tmp;
			tmp.str("");
			tmp << "chkpt." << itr << ".out";
			chkptfile.open(tmp.str());
			chkptfile.write(reinterpret_cast<char const *>(&itr), sizeof(uint32_t));
			chkptfile.write(reinterpret_cast<char const *>(&epsilon), sizeof(float));
			chkptfile.write(reinterpret_cast<char const *>(&rows), sizeof(uint32_t));
			chkptfile.write(reinterpret_cast<char const *>(&cols), sizeof(uint32_t));
			for (uint32_t i = 0; i < rows; i++) {
				for (uint32_t j = 0; j < cols; j++) {
					chkptfile.write(reinterpret_cast<char const *>(&grid1[i][j]), sizeof(float));
				}
			}
			chkptfile.close();
		}
	}

	// human readable test output
	// cout << "Iterator: " << itr << endl;
	// cout << "Epsilon: " << epsilon << endl;
	// cout << "Rows: " << rows << endl;
	// cout << "Columns: " << cols << endl;

	// binary output
	cout.write(reinterpret_cast<char const *>(&itr), sizeof(uint32_t));
	cout.write(reinterpret_cast<char const *>(&epsilon), sizeof(float));
	cout.write(reinterpret_cast<char const *>(&rows), sizeof(uint32_t));
	cout.write(reinterpret_cast<char const *>(&cols), sizeof(uint32_t));
	printGrid(rows, cols, grid1);

	// De-allocate memory
	deleteGrid(rows, grid1);
	deleteGrid(rows, grid2);

	return 0;
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
bool isStable(uint32_t r, uint32_t c, float e, float ** grid) {
	float tmp_val;
	for (uint32_t i = 1; i < r-1; i++) {
		for (uint32_t j = 1; j < c-1; j++) {
			tmp_val = (grid[i-1][j] + grid[i+1][j] + grid[i][j-1] + grid[i][j+1]);
			tmp_val = fabs((tmp_val/4) - grid[i][j]) ;
			if (tmp_val > e) {
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
 * @param e
 *	The value of epsilon
 * @param grid
 *	Dereferenced 2D grid to be recalculated
 * @param tmp
 *	Dereferenced 2D grid to temporarily hold the recalculated values
**/
void recalcGrid(uint32_t r, uint32_t c, float ** grid, float ** tmp) {
	for (uint32_t i = 1; i < r-1; i++) {
		for (uint32_t j = 1; j < c-1; j++) {
			tmp[i][j] = ((grid[i-1][j] + grid[i+1][j] + grid[i][j-1] + grid[i][j+1])/4);
		}
	}

	copyGrid(r, c, tmp, grid);
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
	// human readable test output
	// cout << "Grid: ";
	for (uint32_t i = 0; i < r; i++) {
		for (uint32_t j = 0; j < c; j++) {
			// human readable test output
			// cout << grid[i][j] << " ";

			cout.write(reinterpret_cast<char const *>(&grid[i][j]), sizeof(float));
		}
		// human readable test output
		// cout << endl;
	}
}



