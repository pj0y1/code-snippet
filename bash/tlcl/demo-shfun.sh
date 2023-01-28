#!/bin/bash

dispArray()
{
	echo "inside the function: "
	echo $@
	local sum=0
	for i in "$@";
	do
		sum=$[ sum+i ]
	done
	echo "Sum=$sum"
}

dispArray $@
