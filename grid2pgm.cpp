/**
 * IT 515R - Scientific Computing - Phase 4
 * @author Tanner Satchwell tannersatch@gmail.com
**/

#include <iostream>
#include <algorithm>
#include <cstdint>
#include "grid.h"

#ifndef UINT16_MAX
#define UINT16_MAX 65535
#endif

#ifndef UINT16_MIN
#define UINT16_MIN 0
#endif

using std::cin;
using std::cout;
using std::endl;

uint16_t convert(float val, float min, float max);

int main() {
	// declare vars
	uint32_t itr;
	float epsilon;
	uint32_t rows;
	uint32_t cols;

	float ** grid;

	// read grid from cin
	readGrid(cin, itr, epsilon, rows, cols, grid);

	// find the min and max values in the grid
	float min = grid[0][0];
	float max = grid[0][0];
	for (uint32_t i = 0; i < rows; i++) {
		for (uint32_t j = 0; j < cols; j++) {
			max = (grid[i][j] > max) ? grid[i][j] : max;
			min = (grid[i][j] < min) ? grid[i][j] : min;
		}
	}

	// prepare the pgm file
	cout << "P2" << endl;
	cout << cols << '\t' << rows << endl;
	cout << UINT16_MAX << endl;

	for (uint32_t i = 0; i < rows; i++) {
		for (uint32_t j = 0; j < cols; j++) {
			cout << convert(grid[i][j], min, max) << '\t';
		}
		cout << endl;
	}

	// De-allocate memory
	deleteGrid(rows, grid);

	return 0;
}

/**
 * Convert a given value in the grid porportionally based on UINT16_MAX and UINT16_MIN
 * @param val
 *	The value to be converted
 * @param min
 *	The minimum value in the original grid
 * @param max
 *	The maximum value in the original grid
 * @return
 *	The converted uint16_t grid value
**/
uint16_t convert(float val, float min, float max) {
	float tmp_val = (val-min)/(max-min) * (UINT16_MAX - UINT16_MIN) + UINT16_MIN;
	return (uint16_t) tmp_val;
}
