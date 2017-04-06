/**
 * IT 515R - Scientific Computing - Phase 8
 * @author Tanner Satchwell tannersatch@gmail.com
**/

#include <iostream>
#include <cstdint>
#include <cmath>
#include <sstream>
#include <thread>
#include <vector>
#include <mutex>

#include "barrier.hh"

using std::cout;
using std::cin;
using std::endl;
using std::stringstream;
using std::thread;
using std::vector;
using std::mutex;
using fsl::Barrier;

void initializeGrid(uint32_t &r, uint32_t &c, float ** grid);
void swapGrid(uint32_t &r, uint32_t &c, float ** grid, float ** tmp);
void printGrid(uint32_t &r, uint32_t &c, float ** grid);
void cleanUp(uint32_t &r, float ** grid);

int main(int argc, char *argv[]) {
	// get how many threads
	size_t num_threads;
	if (argc == 2) {
		stringstream tmp;
		tmp << argv[1];
		tmp >> num_threads;
	} else {
		num_threads = 1;
	}

	// declare vars
	uint32_t itr;
	float epsilon;
	uint32_t rows;
	uint32_t cols;
	float error = 0.0f;
	Barrier bar(num_threads);
	mutex mtx;
	bool quit = false;

	cin.read(reinterpret_cast<char *>(&itr), sizeof(uint32_t));
	cin.read(reinterpret_cast<char *>(&epsilon), sizeof(float));
	cin.read(reinterpret_cast<char *>(&rows), sizeof(uint32_t));
	cin.read(reinterpret_cast<char *>(&cols), sizeof(uint32_t));

	float ** grid1;
	float ** grid2;

	// allocate memory
	grid1 = new float * [rows];
	grid2 = new float * [rows];
	for (uint32_t i = 0; i < rows; ++i) {
		grid1[i] = new float [cols];
		grid2[i] = new float [cols];
	}

	// initialize grid
	initializeGrid(rows, cols, grid1);

	// initialize vector of threads
	vector<thread> threads;

	for (uint32_t t = 0; t < num_threads; t++) {
		threads.emplace_back(thread ([&, t]() {
			do {
				for (uint32_t i = 1; i < rows-1; i++) {
					for (uint32_t j = 1; j < cols-1; j++) {
						float average = ((grid1[i-1][j] + grid1[i+1][j] + grid1[i][j-1] + grid1[i][j+1])/4);
						float value = grid1[i][j];

						grid2[i][j] = average;
						float tmp_val = fabs(average-value);

						mtx.lock();
						error = (tmp_val > error) ? tmp_val : error;
						mtx.unlock();
					}
				}

				bar.wait();

				if (t == 0) {
					if (error < epsilon) {
						quit = true;
					} 
				}

				bar.wait();

				if (quit) {
					break;
				}

				if (t == 0) {
					itr ++;
					swapGrid(rows, cols, grid1, grid2);
					error = 0.0f;
				}

				bar.wait();

			} while (true);

		}));
	}

	for (uint32_t t = 0; t < num_threads; t++) {
		threads.at(t).join();
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
	cleanUp(rows, grid1);
	cleanUp(rows, grid2);

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
void initializeGrid(uint32_t &r, uint32_t &c, float ** grid) {
	float tmp_val;
	for (uint32_t i = 0; i < r; i++) {
		for (uint32_t j = 0; j < c; j++) {
			cin.read(reinterpret_cast<char *>(&tmp_val), sizeof(float));
			grid[i][j] = tmp_val;
		}
	}
}

/**
 * A single iteration through the 2D grid to swap from grid1 to grid2.
 * @param r
 *	The number of rows in the 2D grid
 * @param c
 *	The number of columns in the 2D grid
 * @param grid
 *	Dereferenced 2D grid to be recalculated
 * @param tmp
 *	Dereferenced 2D grid to temporarily hold the recalculated values
**/
void swapGrid(uint32_t &r, uint32_t &c, float ** grid, float ** tmp) {
	for (uint32_t i = 1; i < r-1; i++) {
		for (uint32_t j = 1; j < c-1; j++) {
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
void printGrid(uint32_t &r, uint32_t &c, float ** grid) {
	for (uint32_t i = 0; i < r; i++) {
		for (uint32_t j = 0; j < c; j++) {
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
void cleanUp(uint32_t &r, float ** grid) {
	for (uint32_t i = 0; i < r; ++i) {
		delete [] grid[i];
	}
	delete [] grid;
}




