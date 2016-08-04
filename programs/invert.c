#include <stdio.h>
#include <stdlib.h>


//A simple utility for byte-wise inverting the input file
int main(int argc, char* argv[]){
	if(argc < 2){
		printf("Usage: invert <infile>");
		printf("\nOutput will be sent to stdout");
		printf("\nTo use stdin as input, use - as the infile\n");
		exit(1);
	}
	FILE *input = stdin;
	if(argv[1][0] != '-'){
		input = fopen(argv[1],"rb");
		if(input == 0){
			printf("Could not open provided infile");
			exit(1);
		}
	}
	while(1){
		int in = fgetc(input);
		if(in == EOF){
			exit(0);
		}
		char enc = in ^ 0xFF;
		fputc(enc,stdout);
	}
}
