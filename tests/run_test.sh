#!/bin/bash

cd fintech_task_c_dev

COLOR='\e[34m'

ver="dev-v1.x dev-v1.x-printf"

if [ -z "$1" ]
then
  n=10
else
  n=$1
fi

echo -e "\nУстановлено значени количества измерений на одну версию - ${n}"
sleep 0.5

function metric {

  MAX=0
  SUM=0

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
  echo -en "${COLOR}"
  echo -e "Версия $(git branch --show-current) \t--> \tmin: 0${MIN};  max: 0${MAX};  avr: 0${AVR}"
  echo -en "\e[0m"
}

for v in $ver
do
  git checkout ${v}
  echo
  echo -n "Сборка образца ${v}"
  if (( $(make > /dev/null) ))
    then
      echo " - [ERR]"
      exit 1
    else
      echo " - [OK]"
    fi
  echo -n "Измерение "
  metric
done
