#!/bin/bash

#Executing the exit command test

(
	echo "ls ; echo hello;"
	sleep 1
	echo "quit"

) | ../bin/rshell

(
	echo "echo 'hello world"
	sleep 1
	echo "quit"

) | ../bin/rshell

