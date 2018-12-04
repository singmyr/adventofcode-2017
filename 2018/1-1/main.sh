#!/usr/bin/env bash

# --- Day 1: Chronal Calibration --- #

# Run by running:
# ./main.sh < input.txt

FREQ=0

while read line
do
    NUM=`echo "$line" | sed "s/+//;s/-//;s/\n//"`
    if [[ $line == "+"* ]]; then
        FREQ=$((FREQ + NUM))
    elif [[ $line == "-"* ]]; then
        FREQ=$((FREQ - NUM))
    fi
done < "${1:-/dev/stdin}"

echo $FREQ