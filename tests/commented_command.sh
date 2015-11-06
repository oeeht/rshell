#!/bin/bash

#Executing the commented command tests

(
	echo "echo 'hello' #comment"
	sleep 1

	echo "ls -l #comment again"
	sleep 1
	
	echo "quit"

) | ../bin/rshell