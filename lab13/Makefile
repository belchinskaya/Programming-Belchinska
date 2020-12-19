targets = main.bin
target = leak:
	valgrind = --leak-check=yes dist/main1.bin

CC = gcc
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./ task1/src/lib.c  task2/src/lib.c task3/src/lib.c task4/src/lib.c



all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
format:
	doxygen
compile:
	$(CC) $(C_OPTS) task1/src/main.c -o dist/main1.bin
	$(CC) $(C_OPTS) task2/src/main.c -o dist/main2.bin
	$(CC) $(C_OPTS) task3/src/main.c -o dist/main3.bin
	$(CC) $(C_OPTS) task4/src/main.c -o dist/main4.bin 
	
run: clean prep compile
	./dist/main.bin
format: #TODO

tidy: # TODO

