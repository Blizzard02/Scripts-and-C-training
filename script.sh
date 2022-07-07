#!/bin/bash

if [ $# -ne 2 ]
then
  echo "Not right amount of arguments."
else
  if [ ! -d $2 ]
  then
    echo "Directory not exists."
    mkdir $2
    cp $1 $2
  else
    if [ -f $1 ]
      echo "File already exists."
      if [ -w $1 ] 
      then
        $1 > $1
      else
        echo "File cannot be over-written."
      fi
    fi
  fi
fi
