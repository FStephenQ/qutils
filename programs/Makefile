PWD := $(shell echo $(PWD))

file_weight: file_weight.c hamming.o
	gcc -iquote ../lib/C -o bin/file_weight file_weight.c hamming.o -std=c99
	rm hamming.o

hamming.o:
	gcc -c ../lib/C/hamming.c -std=c99

xor: 
	gcc -o bin/xor xor.c

binary_convert: bin2ascii.o
	gcc -iquote ../lib/C -o bin/binary_convert bin2ascii.o binary_convert.c
	rm bin2ascii.o

bin2ascii.o:
	gcc -c ../lib/C/bin2ascii.c

invert:
	gcc -o bin/invert invert.c

explode:
	gcc -o bin/explode explode.c

clean:
	rm -f hamming.o bin2ascii.o bin/file_weight bin/xor bin/binary_convert bin/invert bin/explode

all: file_weight xor binary_convert invert

install: all
	@echo $(PWD)
	ln -s $(PWD)/bin/* /usr/bin/ 
