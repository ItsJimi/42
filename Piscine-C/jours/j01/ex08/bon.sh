#/bin/sh
ldapsearch -Q sn | grep 'BON' | wc -l | tr -d " "
