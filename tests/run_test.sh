#!/bin/bash

function metric {

  MAX=0
  SUM=0
  n=10

  for (( i = 0; i < n; i++ ))
  do
    res1=$(date +%s.%N)
    cat data/input.txt | ./simulator > /dev/null
    res2=$(date +%s.%N)
    TEST=$(echo "$res2 - $res1" | bc)
    if [[ -z $MIN ]]
    then
      MIN=$TEST
    fi
    if (( $(echo "$TEST<$MIN" | bc -l) ))
    then
      MIN=$TEST
    fi
    if (( $(echo "$TEST>$MAX" | bc -l) ))
    then
      MAX=$TEST
    fi
    SUM=$(bc<<<"$SUM+$TEST")
    echo -n .
    sleep 0.1
  done
  echo
  AVR=$(bc<<<"scale=4;$SUM/$i")
  MIN=$(bc<<<"scale=4;$MIN/1")
  MAX=$(bc<<<"scale=4;$MAX/1")
  echo "min: 0${MIN};  max: 0${MAX};  avr: 0${AVR}"
}

rm ./simulator
make

git checkout dev-v1.x
echo "Измерение версии "$(git branch --show-current)
metric

git checkout dev-v1.x-printf
echo "Измерение версии "$(git branch --show-current)
metric
