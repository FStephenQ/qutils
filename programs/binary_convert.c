/*********************
 * binaryConverter.c
 * By; F. Stephen Quaratiello
 *
 * A simple program to convert an ascii string of 1's and 0's into that string
 * in actual binary, or to convert actual binary into a string of 1's and 0's.
 * 
 * A trivial problem, but a fun one to mess around with.
 *
 ***********************/

#include <stdio.h>
#include <stdlib.h>
#include "bin2ascii.h"


int main(int argc, char* argv[]){ //usage definition
	if(argc < 4){
		printf("The proper usage is: biconv <e/d> <infile> <outfile>. \nTo get input from stdin, use - for the infile\nTo write output to stdout, use - for the outfile\n");
		exit(0);
	}
	else{ 
		char flag = argv[1][0]; //to determine if we are Encoding or Decoding
		FILE *input = stdin;
		if(*(argv[2]) != '-'){
			input = fopen(argv[2], "r");
			if(input == 0){
				printf("Could not open file");
				exit(1);
			}
		}
		FILE *output = stdout;
		if(*(argv[3]) != '-'){
			output = fopen(argv[3], "wb");
			if(output == 0){
				printf("Could not open outfile");
				exit(1);
			}
		}
		if(flag == 'd'){ //if we are encoding, encode
			ascii2bin(input,output);
		}
		else{ //catch-all case for decoding.
			bin2ascii(input, output);
		}
		fclose(output);
		fclose(input);
	}
	exit(0);
}




