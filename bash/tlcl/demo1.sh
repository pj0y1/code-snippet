#!/bin/bash
# make journal file
suffix=$(date +%m%d)
touch log.$suffix
cat << EOF
1. choose the clothes
2. choose a job
3. choose a house
4. choose to live or die 
EOF
# called a here document
echo $((2**5))
echo $(expr 2 \* 9)
echo $text
result=$(echo "5.55 > 3" | bc)
if [ $result -eq 1 ]
then
	echo "be a loser"
else
	echo "who am i?"
fi
value=396
exit $value
