#include <stdio.h>
#include <stdlib.h>


//A simple utility for byte-wise XORing two files together
int main(int argc, char* argv[]){
	if(argc < 3){
		printf("Usage: xor <infile> <keyfile>");
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
	FILE *keyfile = fopen(argv[2],"rb");
	if(keyfile == 0){
		printf("Could not open provided keyfile");
		exit(1);
	}
	while(1){
		int in = fgetc(input);
		if(in == EOF){
			exit(0);
		}
		int key = fgetc(keyfile);
		if(key == EOF){
			fclose(keyfile);
			keyfile = fopen(argv[2],"rb");
			key = fgetc(keyfile);
			if(key == EOF){
				exit(1);
			}
		}
		char enc = in ^ key;
		fputc(enc,stdout);
	}
}
