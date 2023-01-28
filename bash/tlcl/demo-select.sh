#!/bin/bash
PS3="Enter your option: "
select option in "Bullshit" "Nonsense" "Dumbass"
do 
	case $option in
		"Bullshit") echo "Bullshit tastes good, can you believe it?";;
		"Nonsense") echo "You are adorable even if you talk such nonsense.";;
		"Dumbass" ) echo "Better to be a dumbass rather than an asshole XD";;
		* )	echo "No, you little fool run into noplace";;
	esac
done
