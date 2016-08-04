#include <stdio.h>
#include <stdlib.h>


//A simple utility for explode a file into a double-length file where two adjacent characters XOR to the single character in the original file at that position.
int main(int argc, char* argv[]){
	if(argc < 2){
		printf("Usage: explode <infile>");
		printf("\nOutput will be sent to stdout");
		printf("\nTo use stdin as the infile, use - as the infile");
		exit(1);
	}
	FILE *input = stdin;
	if(argv[1][0] != '-'){
		input = fopen(argv[1],"rb");
		if(input == 0){
			printf("Could not open provided infile\n");
			exit(1);
		}
	}
	FILE *rand = fopen("/dev/urandom","rb");
	while(1){
		int in = fgetc(input);
		if(in == EOF){
			exit(0);
		}
		char key_char = fgetc(rand);
		char result_char = in^key_char;
		fputc(key_char,stdout);
		fputc(result_char, stdout);
	}
}
