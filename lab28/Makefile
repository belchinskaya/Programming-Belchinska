targets = main.bin test.bin

CС = g++
C_OPTS = -g -Wall -lstdc++ -std=c++11 -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src src/data.cpp 


all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
format:
	doxygen
compile: main.bin test.bin

main.bin: src/main.cpp
	$(CC) $(C_OPTS) $< -o ./dist/$@
test.bin: test/test.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
test: clean prep compile
	./dist/test.bin
run: clean prep compile
	./dist/main.bin
format: #TODO

tidy: # TODO

