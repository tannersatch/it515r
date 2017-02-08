# IT 515R - Scientific Computing - Shell and Slurm Practice
### Tanner Satchwell
### tannersatch@gmail.com

## Job Launch Instructions

sbatch energize.sh

## Other Information

This job will launch an array of size 10 using "-a 1-10" and will also launch a separate job, analyze.awk, that depends on the successful completion of the job array. Dependency is set using "-d afterok:SLURM_ARRAY_JOB_ID"

Final result is stored in: array_min.out
