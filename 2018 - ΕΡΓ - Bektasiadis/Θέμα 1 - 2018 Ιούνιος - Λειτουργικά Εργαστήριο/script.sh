#!/bin/bash

argc=$#
argv=("$@")

for (( i=0; i<$argc; i+=2 ))
do
  echo "Currently moving ${argv[i]} to ${argv[i+1]}"
  sh move.sh ${argv[$i]} ${argv[$i+1]}
done
