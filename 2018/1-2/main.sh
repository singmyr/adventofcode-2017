#!/usr/bin/env bash

# --- Day 1: Chronal Calibration --- #

# Bash version: GNU bash, version 4.4.23(1)-release (x86_64-apple-darwin17.5.0)
# Run by running:
# ./main.sh

FREQ=0

declare -A SEEN
SEEN[NONE0]=1

while true
do
    echo "LEN: ${#SEEN[*]}"
    while read line
    do
        NUM=`echo "$line" | sed "s/+//;s/-//"`
        if [[ $line == "+"* ]]; then
            FREQ=$((FREQ + NUM))
        elif [[ $line == "-"* ]]; then
            FREQ=$((FREQ - NUM))
        fi

        if [[ $FREQ > 0 ]]; then
            KEY="PLUS$FREQ"
        elif [[ $FREQ < 0 ]]; then
            KEY="MINUS${FREQ#-}"
        else
            KEY="NONE$FREQ"
        fi
        
        if [ "${SEEN[$KEY]}" == 1 ]; then
            echo "FOUND $FREQ"
            exit
        fi
        SEEN[$KEY]=1
    done < input.txt
done
