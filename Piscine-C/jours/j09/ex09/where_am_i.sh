#!/bin/sh

ip=`ifconfig | grep "inet " | cut -d ' ' -f2 | awk '{if ($0 != "127.0.0.1") print}'`
if [ "$ip" == "" ];
then
	echo "Je suis perdu!\n"
else
	echo "$ip"
fi

exit 0
