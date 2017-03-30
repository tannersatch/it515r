#!/bin/bash

#SBATCH --time=01:00:00 --nodes=1 --mem=32G --exclusive -p m7

echo "Single Thread Running..."
echo "See single_time.txt for time results"
export OMP_NUM_THREADS=1
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> single_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> single_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> single_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> single_time.txt

echo "Two Threads Running..."
echo "See two_time.txt for time results"
export OMP_NUM_THREADS=2
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> two_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> two_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> two_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> two_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> two_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> two_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> two_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> two_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> two_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> two_time.txt

echo "Four Threads Running..."
echo "See four_time.txt for time reslts"
export OMP_NUM_THREADS=4
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> four_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> four_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> four_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> four_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> four_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> four_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> four_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> four_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> four_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> four_time.txt

echo "Eight Threads Running..."
echo "See eight_time.txt for time results"
export OMP_NUM_THREADS=8
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> eight_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> eight_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> eight_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> eight_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> eight_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> eight_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> eight_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> eight_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> eight_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> eight_time.txt

echo "Sixteen Threads Running..."
echo "See sixteen_time.txt for time results"
export OMP_NUM_THREADS=16
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> sixteen_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> sixteen_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> sixteen_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> sixteen_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> sixteen_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> sixteen_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> sixteen_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> sixteen_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> sixteen_time.txt
{ time ./openmp < phase7/phase7.in.grid > tmp.binary ; } 2>> sixteen_time.txt

echo "Done"
