#/bin/sh
ldapsearch -Q -LLL "(uid=z*)" | grep "cn: " | cut -d " " -f2,3 | sort -r
