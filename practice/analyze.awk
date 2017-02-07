#!/bin/bash

# IT 515R - Scientific Computing - Shell and Slurm Practice
# @author Tanner Satchwell tannersatch@gmail.com

#SBATCH --time=00:00:05
#SBATCH --ntasks=1
#SBATCH --nodes=1
#SBATCH --mem=1G
#SBATCH -o array_min.out

# Find smallest randomly generated number in the array
awk 'BEGIN { getline; id=$1; min=$NF }
{
	id=(min>$NF)?$1:id;
	min=(min>$NF)?$NF:min;
}
END {print id, min}' $1.*
