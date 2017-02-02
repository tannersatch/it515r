#!/bin/bash

#SBATCH --ntasks=1 --mem=1G --time=00:00:04 -a 1-10

echo "$SLURM_ARRAY_TASK_ID $RANDOM" > "$SLURM_ARRAY_JOB_ID.$SLURM_ARRAY_TASK_ID.out"

exit 0
