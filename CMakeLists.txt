cmake_minimum_required(VERSION 3.6)

project(Phase7 CXX)

add_executable(solver solver.cpp)
add_executable(binary binary.cpp)
add_executable(openmp openmp.cpp)
add_executable(threads threads.cpp)

set_target_properties(solver binary openmp threads
	PROPERTIES
	CXX_STANDARD 14
	CXX_EXTENSIONS FALSE
	CXX_STANDARD_REQUIRED TRUE
)

find_package(OpenMP REQUIRED)
message("Flags: ${OpenMP_CXX_FLAGS}")
set_target_properties(openmp 
	PROPERTIES
	COMPILE_FLAGS	"${OpenMP_CXX_FLAGS}"
	LINK_FLAGS	"${OpenMP_CXX_FLAGS}"
)

find_package(Threads REQUIRED)
message("Flags: ${CMAKE_THREAD_LIBS_INIT}")
set_target_properties(threads
	PROPERTIES
	LINK_FLAGS "${CMAKE_THREAD_LIBS_INIT}"
)