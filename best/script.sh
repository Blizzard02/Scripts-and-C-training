argc=$#
argv=("$@")

for (( i=0; i<$argc; i+=2 ))
do
  if [ $# -ne 2 ]; then
    echo "Not right amount of arguments."
  else
    if [ ! -f $argc[i+1] ]; then
      echo "File doesn't exist."
      cp $argv[i] $argv[i+1]
      echo "$argv[i] has been copied to ./$argv[i+1]"
    else
      if [ -w $argc[i+1] ]; then
        $argv[i] > $argv[i+1
      else
        echo "File cannot be over-written."
     fi
  fi
done
