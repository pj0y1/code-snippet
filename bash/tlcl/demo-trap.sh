#!/bin/bash
makeBigNews()
{
	echo "Too Young Too Simple, Sometimes Naive"
	echo "According to Fundamental Law ..."
	exit 1
}

trap makeBigNews SIGINT
trap "echo goodbye ..." EXIT

cnt=1
while [ $cnt -lt 10 ]
do
	echo "$cnt"
	cnt=$[ cnt+1 ]
	sleep 1
done
