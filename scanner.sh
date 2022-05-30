fc=0
dc=0
max_sizes=(0 0 0)
max_names=("" "" "")

check_dir () {
	for i in `ls $1`;do
		if [ -f $1/$i ];then
			#echo it is file
			fc=$(($fc+1))
			size=`stat -c %s $1/$i`
			if [ $size -gt ${max_sizes[0]} ];then
				max_sizes[2]=${max_sizes[1]}
				max_sizes[1]=${max_sizes[0]}
				max_sizes[0]=$size
                                max_names[2]=${max_names[1]}
                                max_names[1]=${max_names[0]}
                                max_names[0]=$1/$i
			elif [ $size -gt ${max_sizes[1]} ];then
                                max_sizes[2]=${max_sizes[1]}
                                max_sizes[1]=$size
                                max_names[2]=${max_names[1]}
                                max_names[1]=$1/$i
                        elif [ $size -gt ${max_sizes[2]} ];then
                                max_sizes[2]=$size
                                max_names[2]=$1/$i
			fi
		else
			#echo it is dir
			dc=$(($dc+1))
			check_dir $1/$i
		fi
	done
}

check_dir $1

echo Found $fc files and $dc dirs
for i in `seq 0 2`;do
	echo ${max_names[$i]} - ${max_sizes[$i]}
done
