#compiler
CC = g++

#compiler flags
CFLAGS = -Wall -Werror -ansi -pedantic

#
all:
	mkdir -p bin
	$(CC) $(CFLAGS) ./src/main.cpp -o rshell

rshell:
	main.cpp
	$(CC) $(CFLAGS) ./src/main.cpp -o rshell

