targets = main.bin
CC = gcc
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src 

all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
compile:
	$(CC) $(C_OPTS) 2.2/src/main.c -o dist/main2.2.bin
	$(CC) $(C_OPTS) 2.3/src/main.c -o dist/main2.3.bin
	$(CC) $(C_OPTS) 3/src/main.c -o dist/main3.bin
	$(CC) $(C_OPTS) 3.1/src/main.c -o dist/main3.1.bin
	$(CC) $(C_OPTS) 3.2/src/main.c -o dist/main3.2.bin
	$(CC) $(C_OPTS) 3.3/src/main.c -o dist/main3.3.bin
	$(CC) $(C_OPTS) 3.4/src/main.c -o dist/main3.4.bin
	$(CC) $(C_OPTS) 3.5/src/main.c -o dist/main3.5.bin
	$(CC) $(C_OPTS) 3.6/src/main.c -o dist/main3.6.bin
run: clean prep compile
	./dist/main.bin
doxygen:
	doxygen Doxyfile
format: #TODO

tidy: # TODO

