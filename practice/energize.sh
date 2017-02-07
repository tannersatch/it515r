#!/bin/bash

# IT 515R - Scientific Computing - Shell and Slurm Practice
# @author Tanner Satchwell tannersatch@gmail.com

#SBATCH --time=00:00:05
#SBATCH --ntasks=1
#SBATCH --nodes=1
#SBATCH --mem=1G
#SBATCH -a 1-10
#SBATCH -o %A.%a.out

# Launch the awk job once, depending on the successful completion of the array
if [ $SLURM_ARRAY_TASK_ID == 1 ]
then
	sbatch -d afterok:$SLURM_ARRAY_JOB_ID analyze.awk $SLURM_ARRAY_JOB_ID &> /dev/null
fi

# Print the array task ID followed by a random number
echo "$SLURM_ARRAY_TASK_ID $RANDOM"

exit 0
