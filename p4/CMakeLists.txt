cmake_minimum_required(VERSION 3.6)

project(Phase4 CXX)

add_executable(solver solver.cpp)
add_executable(binary binary.cpp)
add_executable(grid2pgm grid2pgm.cpp)

set_target_properties(solver PROPERTIES
	CXX_STANDARD 14
	CXX_EXTENSIONS FALSE
	CXX_STANDARD_REQUIRED TRUE
)

set_target_properties(grid2pgm PROPERTIES
        CXX_STANDARD 14
        CXX_EXTENSIONS FALSE
        CXX_STANDARD_REQUIRED TRUE
)

set_target_properties(binary PROPERTIES
        CXX_STANDARD 14
        CXX_EXTENSIONS FALSE
        CXX_STANDARD_REQUIRED TRUE
)
