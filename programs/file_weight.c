#include <stdio.h>
#include <stdlib.h>
#include "hamming.h"


//A simple utility for finding the hamming weight of a file
int main(int argc, char* argv[]){
	FILE *input = stdin;
	if(argv[1][0] != '-'){
		input = fopen(argv[1],"rb");
		if(input == 0){
			printf("Could not open provided infile");
			exit(1);
		}
	}
	long long total = 0l;
	while(1){
		int in = fgetc(input);
		if(in == EOF){
			break;
		}
		total += hamming_weight(in);
	}
	printf("%lld",total);
	//printf("%ld\n",void_hamming_weight((&total),sizeof(long long)));
}
