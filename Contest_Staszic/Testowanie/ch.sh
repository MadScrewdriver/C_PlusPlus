#!/bin/bash

for ((i = 1; i > 0; i++))
do
	echo $i | ./gen > in.in
	./wzor <in.in> zle.out
	./brut <in.in> dobre.out

	if diff -qb zle.out dobre.out > /dev/null
		then echo  "test $i              OK"
		else echo  "test $i              WRONGGGGGG AAAA HELP!!!"
		break;
	fi
done
