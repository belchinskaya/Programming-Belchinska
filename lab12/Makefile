targets = main.bin
CC = gcc
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src src/lib.c 

all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
format:
	doxygen
compile: main.bin

main.bin: src/main.c
	$(CC) $(C_OPTS) src/main.c -o dist/main1.bin

run: clean prep compile
	dist/main.bin
format: #TODO

tidy: # TODO

