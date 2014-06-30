CC = clang++ -Wall -O2

bin/my-lisp: src/*.cpp src/*.cpp
	$(CC) -o $@ src/*.cpp

build: bin/my-lisp

test: my-lisp
	echo TODO

.PHONY: build