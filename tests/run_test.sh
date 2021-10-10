#!/bin/bash

for (( i = 0; i < 10; i++ ))
do
  TEST="$({cat data/input.txt | /usr/bin/time -f '%U' ./simulator 1> /dev/null} 2>&1)"
  if [!$MIN]
  then
    MIN=$TEST
  fi
  if [$TEST > $MAX]
  then
    MAX=$TEST
  fi
done
echo "min: ${MIN};\t max: ${MAX}"
