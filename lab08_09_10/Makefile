targets = main.bin
CC = gcc
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src 

all: clean prep compile run 

clean:
	rm -rf dist
prep:
	mkdir dist
format:
	doxygen
compile:
	
	$(CC) $(C_OPTS) lab05_task3/src/main.c -o dist/main3.1.bin
	$(CC) $(C_OPTS) lab06_task3/src/main.c -o dist/main3.2.bin
run: clean prep compile
	./dist/main.bin

format: #TODO

tidy: # TODO

