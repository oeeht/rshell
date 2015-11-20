Théo CORIN, tcori003 (623701) and Jérôme MATTA, jmatta008(623700)

RSHELL
==============
rshell is an executable that is a basic command shell

Installation
---------------
How to use rshell :

	* git clone https://github.com/oeeht/
	* cd rshell
	* git checkout hw1
	* make
	* bin/rshell

What it does 
---------------
You can execute simple commands such as
Examples:

	* ls -l
	* echo "Hello World"
	* pwd

You can add comments while typing a command
Examples:
	* echo Hello #This is a comment
It will not print the "#This is a comment" part

Test command
---------------
Examples:
* test -e /home
* test /home
* [ /home ]
* [ -e /home ]


Exit
---------------
Supposed to exit by typing "exit" but does not work properly

Bugs
---------------
We didn't understand everything about the fork...
Most of the times the program doesn't recognize the command "exit" to quit the program.
YOU HAVE TO END YOUR LINE WITH A ';' WHEN YOU WRITE MULTIPLE COMMANDS
There are some problems while executing the test scripts.
You cannot write a comment after the first command while doing a multiple commands, you have to add the comments at the end.
