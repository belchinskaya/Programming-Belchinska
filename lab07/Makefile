targets = main.bin
CC = gcc
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src 

all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
compile:
	$(CC) $(C_OPTS) task1_lab05/src/main.c -o dist/main1.1.bin
	$(CC) $(C_OPTS) task1_lab06/src/main.c -o dist/main1.2.bin
	$(CC) $(C_OPTS) task2_lab05/src/main.c -o dist/main2.1.bin
	$(CC) $(C_OPTS) task2_lab06/src/main.c -o dist/main2.2.bin
	$(CC) $(C_OPTS) task3_lab05/src/main.c -o dist/main3.1.bin
	$(CC) $(C_OPTS) task3_lab06/src/main.c -o dist/main3.2.bin
	$(CC) $(C_OPTS) task4_lab05/src/main.c -o dist/main4.1.bin
	$(CC) $(C_OPTS) task4_lab06/src/main.c -o dist/main4.2.bin
	$(CC) $(C_OPTS) task5_lab05/src/main.c -o dist/main5.1.bin
	$(CC) $(C_OPTS) task5_lab06/src/main.c -o dist/main5.2.bin
	$(CC) $(C_OPTS) task6_lab06/src/main.c -o dist/main6.1.bin
run: clean prep compile
	./dist/main.bin
doxygen:
	doxygen Doxyfile
format: #TODO

tidy: # TODO

