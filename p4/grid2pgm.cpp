#include <iostream>
#include <algorithm>
#include <cstdint>
#include "grid.h"

#define UINT16_MAX 65535;

using std::cin;
using std::cout;
using std::endl;
using std::max_element();
using std::min_element();
using std::minmax_element();

uint16_t tween(float val, float min, float max, uint16_t min_pgm, uint16_t max_pgm);

int main() {

	uint32_t itr;
	float epsilon;
	uint32_t rows;
	uint32_t cols;
	float * data;

	readGrid(cin, itr, epsilon, rows, cols, data);

	auto minmax = minmax_element(data, data + (rows * cols));

	float fmin = *minmax.first;
	float fmax = *minmax.second;

	cout << "P2" << endl;
	cout << cols << '\t' << rows << endl;
	cout << UINT16_MAX << endl;

	for (uint32_t i = 0; i < rows; i++) {
		cout << tween(data[0], fmin, fmax, 0, UINT16_MAX);
		for (uint32_t j = 1; j < cols; j++) {
			cout << '\t' << tween(data[j], fmin, fmax, 0, UINT16_MAX);
		}
		cout << endl;
	}

	return 0;
}


uint16_t tween(float val, float min, float max, uint16_t min_pgm, uint16_t max_pgm) {

}


/*

[x, y] -> [a, b]

(v-x)/(y-x) * (b-a) + a

*/