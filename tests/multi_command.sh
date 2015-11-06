#!/bin/bash

#Executing the multiple command tests

(
	echo "echho a || echo b"
	sleep 1

	echo "echo a && echo b"
	sleep 1

	echo "echo a; echo b;"
	sleep 1

	echo "echho a || echo b && echo c"
	sleep 1

	echo "echo a || echo b; echo c && echo d"
	sleep 1

	echo "quit"

) | ../bin/rshell
