#!/bin/bash

if [ $1 == 'e' ]
then
	iteration=0
	touch /tmp/key
	while [ $(./filelength.sh /tmp/key) -le $(./filelength.sh $2) ]
	do
		current_key=/tmp/randkey.$iteration
		./genrand.sh $RANDOM > $current_key
		let "iteration += 1"
		file_weight $current_key  >> /tmp/key
	done
	xor $2 /tmp/key > /tmp/out
	tar -cf /tmp/keyball /tmp/randkey.*
	rm /tmp/randkey.* /tmp/key
	exit
else 
	for n in $(tar -xvf $1)
	do
		touch /tmp/key
		file_weight $n >> /tmp/key
		rm $n
	done
	xor $2 /tmp/key > /tmp/original
	rm /tmp/key
	exit
fi
