targets = main.bin

CC = gcc
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./ src/lib.c



all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
format:
	doxygen
compile:

	$(CC) $(C_OPTS) src/main.c -o dist/main3.bin

run: clean prep compile
	./dist/main.bin
format: #TODO

tidy: # TODO

