/**
 * IT 515R - Scientific Computing - Phase 4
 * @author Tanner Satchwell tannersatch@gmail.com
**/

#include <iostream>
#include <algorithm>
#include <cstdint>
#include "grid.h"

#define UINT16_MAX 65535
#define UINT16_MIN 0

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

	float ** grid1;
	float ** grid2;

	// read grid from cin
	readGrid(cin, itr, epsilon, rows, cols, grid1, grid2);

	// find the min and max values in the grid
	float min = grid1[rows][cols];
	float max = grid1[rows][cols];
	for (uint32_t i = 1; i < rows; i++) {
		for (uint32_t j = 1; j < cols; j++) {
			max = (grid1[i][j] > max) ? grid1[i][j] : max;
			min = (grid1[i][j] < min) ? grid1[i][j] : min;
		}
	}

	// prepare the pgm file
	cout << "P2" << endl;
	cout << cols << '\t' << rows << endl;
	cout << UINT16_MAX << endl;

	for (uint32_t i = 0; i < rows; i++) {
		for (uint32_t j = 0; j < cols; j++) {
			cout << convert(grid1[i][j], min, max) << '\t';
		}
		cout << endl;
	}

	// De-allocate memory
	cleanUp(rows, grid1);
	cleanUp(rows, grid2);

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
