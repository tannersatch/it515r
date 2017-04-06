#!/bin/bash

#SBATCH --time=01:00:00 --nodes=1 --mem=32G --exclusive -p m7

echo "Single Thread Running..."
echo "See single_time.txt for time results"
{ time ./threads 1 < phase7/phase7.in.grid > tmp.binary ; } 2>> t_single_time.txt

echo "Two Threads Running..."
echo "See two_time.txt for time results"
{ time ./threads 2 < phase7/phase7.in.grid > tmp.binary ; } 2>> t_two_time.txt

echo "Four Threads Running..."
echo "See four_time.txt for time reslts"
{ time ./threads 4 < phase7/phase7.in.grid > tmp.binary ; } 2>> t_four_time.txt

echo "Eight Threads Running..."
echo "See eight_time.txt for time results"
{ time ./threads 8 < phase7/phase7.in.grid > tmp.binary ; } 2>> t_eight_time.txt

echo "Sixteen Threads Running..."
echo "See sixteen_time.txt for time results"
{ time ./threads 16 < phase7/phase7.in.grid > tmp.binary ; } 2>> t_sixteen_time.txt

echo "Done"
