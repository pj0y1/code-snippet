#!/bin/bash
clear
tmp=$(mktemp tmp.XXX)
while true
do
	dialog --no-shadow --menu "menu title" 20 30 10 1 "display date" 2 "display working dir" 3 "exit menu" 2>$tmp
	if [ $? -eq 1 ]
	then
		break
	fi

	option=$(cat $tmp)
	case $option in
	1) dialog --msgbox "$(date)" 20 20;;
	2) dialog --msgbox "$(pwd)" 20 20 ;;
	3) break;;
	*) dialog --msgbox "invalid option" 10 20;;
	esac
done

rm -f $tmp 2> /dev/null
