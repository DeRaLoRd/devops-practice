#!/bin/bash

inputList=("omg. this is my first input. that is crazy work man." "tis a senond. string." "lol third")

while true; do

	for input in "${inputList[@]}"; do
	echo "----------------------------"
	echo "input : $input"
	temp=$(sentrim "$input")
	echo "output: $temp"
	sleep 1.0

	done

done
