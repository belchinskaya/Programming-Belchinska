targets = main.bin

CC = gcc
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./ task1/src/lib.c  



all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
format:
	doxygen
compile:
	$(CC) $(C_OPTS) task1/src/main.c -o dist/main1.bin

	
run: clean prep compile
	./dist/main.bin
format: #TODO

tidy: # TODO

