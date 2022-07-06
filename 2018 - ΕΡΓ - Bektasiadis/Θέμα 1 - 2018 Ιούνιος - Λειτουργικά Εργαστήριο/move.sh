#!/bin/bash

if [ $# -ne 2 ]
then
  echo "Not right amount of arguments."
else
  if [ ! -d $2 ]
  then
    echo "Directory not exists."
    mkdir $2
  fi

  if [ ! -f $1 ]
  then
    echo "File not exists."
    touch $1
  fi

  mv $1 $2/$1
  echo "Done. $1 has been moved to ./$2"
fi
