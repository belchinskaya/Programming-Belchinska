targets = main.bin test.bin

CC = clang
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src src/data.c src/list.c


all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
format:
	doxygen
compile:
	$(CC) -I../shared -L../shared -llist src/main.c -o dist/main.bin
	$(CC) -I../shared -L../shared -lentity src/main.c -o dist/main.bin
run: clean prep compile
	cp ../shared/liblist.so ./dist
	./dist/main.bin
format: #TODO

tidy: # TODO

