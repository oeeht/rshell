#!/bin/sh

#Executing the single command tests

(
	echo "echo \"mkdir newfile\""
	echo "mkdir newfile"
	sleep 1

	echo "echo \"mkdir newfile\""
	echo "mkdir newfile"
	sleep 1

	echo "echo \"touch filename\""
	echo "echo touch filenqme"
	sleep 1

	echo "echo \"pwd\""
	echo "pwd"
	sleep 1

	echo "echo \"ls _l\""
	echo "ls _l"
) | ./bin/rshell