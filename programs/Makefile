file_weight: file_weight.c hamming.o
	gcc -o bin/file_weight file_weight.c hamming.o -std=c99
	rm hamming.o

hamming.o:
	gcc -c ../lib/hamming.c -std=c99

xor: 
	gcc -o bin/xor xor.c

binary_convert:
	gcc -o bin/binary_convert binary_convert.c

clean:
	rm -f hamming.o bin/file_weight bin/xor bin/binary_convert

all: file_weight xor binary_convert
