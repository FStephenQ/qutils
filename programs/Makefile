file_weight: file_weight.c hamming.o
	gcc -o bin/file_weight file_weight.c hamming.o -std=c99
	rm hamming.o

hamming.o:
	gcc -c ../lib/hamming.c -std=c99

xor: 
	gcc -o bin/xor xor.c

binary_convert: bin2ascii.o
	gcc -o bin/binary_convert bin2ascii.o binary_convert.c
	rm bin2ascii.o

bin2ascii.o:
	gcc -c ../lib/bin2ascii.c

clean:
	rm -f hamming.o bin/file_weight bin/xor bin/binary_convert

all: file_weight xor binary_convert
