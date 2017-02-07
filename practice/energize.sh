#!/bin/bash

#SBATCH --time=00:00:05
#SBATCH --ntasks=1
#SBATCH --nodes=1
#SBATCH --mem=1G
#SBATCH -a 1-10
#SBATCH -o %A.%a.out

echo "$SLURM_ARRAY_TASK_ID $RANDOM"

exit 0
