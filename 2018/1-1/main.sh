#!/usr/bin/env bash

# --- Day 1: Chronal Calibration --- #

# Run by running:
# ./main.sh

FREQ=0

while read line
do
    NUM=`echo "$line" | sed "s/+//;s/-//;s/\n//"`
    if [[ $line == "+"* ]]; then
        FREQ=$((FREQ + NUM))
    elif [[ $line == "-"* ]]; then
        FREQ=$((FREQ - NUM))
    fi
done < input.txt

echo $FREQ