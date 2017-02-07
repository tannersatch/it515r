#!/bin/bash

#SBATCH --time=00:00:05
#SBATCH --ntasks=1
#SBATCH --nodes=1
#SBATCH --mem=1G
#SBATCH --qos=test

awk 'BEGIN { getline; id=$1; min=$NF }
{ id=(min>$NF)?$1:id; min=(min>$NF)?$NF:min; }
END {print id, min}' $1.*
