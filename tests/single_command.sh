#!/bin/bash

#Executing the single command tests

(
	echo "mkdir newfolder"
	sleep 1

	echo "touch filename.cpp"
	sleep 1

	echo "pwd"
	sleep 1

	echo "ls -l"
	sleep 1

	echo "quit"

) | ../bin/rshell