#!/usr/bin/env bash

# --- Day 1: Chronal Calibration --- #

# Bash version: GNU bash, version 4.4.23(1)-release (x86_64-apple-darwin17.5.0)
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