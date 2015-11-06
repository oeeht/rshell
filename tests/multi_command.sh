#!/bin/sh

#Executing the multiple command tests

(
	echo "echo \"echo a || echo b\""
	echo "echo a || echo b"
	sleep 1

	echo "echo \"echo a && echo b\""
	echo "echo a && echo b"
	sleep 1

	echo "echo \"echo a; echo b\""
	echo "echo a; echo b"
	sleep 1

	echo "echo \"echo a || echo b && echo c\""
	echo "echo a || echo b && echo c"
	sleep 1

	echo "echo \"echo a || echo b; echo c && echo d\""
	echo "echo a || echo b; echo c && echo d"
) | ./bin/rshell