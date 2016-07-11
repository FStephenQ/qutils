file_weight: file_weight.c hamming.o
	gcc -o bin/file_weight file_weight.c hamming.o -std=c99
	rm hamming.o

hamming.o:
	gcc -c ../lib/hamming.c -std=c99

xor: 
	gcc -o bin/xor xor.c

clean:
	rm -f hamming.o bin/file_weight bin/xor

all: file_weight xor
