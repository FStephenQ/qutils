/*********************
 * binaryConverter.c
 * By; F. Stephen Quaratiello
 *
 * A simple program to convert an ascii string of 1's and 0's into that string
 * in actual binary, or to convert actual binary into a string of 1's and 0's.
 * 
 * A trivial problem, but a fun one to mess around with.
 *
 * No Rights Reserved
 ***********************/

#include <stdio.h>
#include <stdlib.h>

void encode(FILE *input, FILE *output, char flag);
void decode(FILE *input, FILE *output);

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
			decode(input,output);
		}
		else{ //catch-all case for decoding.
			encode(input, output, ' ');
		}
		fclose(output);
		fclose(input);
	}
	exit(0);
}

/*******************************
 * For our purposes, encoding
 * refers to converting binary
 * data into an ascii string of
 * 1's and 0's...
 ********************************/

void encode(FILE *input,FILE *output, char flag){
	char hex[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	while(1){
		int x = fgetc(input);
		if(x==EOF)break;
		int num;
		int hold = 0;
		for(num = 0; num<8;num++){
			if((char)(x<<num)>>8){ //fun bit-shifting
				if(flag == 'h'){ //future functionality will add support for hexidecimal encoding
					hold+=(num%4)*2;
					if(!(num%4)) hold+=1;
				}
				else fputc('1', output);
			}
			else{
				if(flag!='h')fputc('0',output);
			}
			if(flag == 'h'&&(num == 3 || num == 7)){
				fputc(hex[hold], output);
				hold = 0;
			}
		}
	}
	return;
}

//... And decoding refers to the inverse.

void decode(FILE *input,FILE *output){
	unsigned char holder = 0;
	int num = 0;
	while(1){
		int x = fgetc(input);
		if(x == EOF) break;
		holder <<= 1;
		if(x == '1'){
			holder = holder | 1; //bitwise opperations are *fun*.
		}
		num++;
		if(num%8 == 0){
			fputc(holder, output);
			holder = 0;
		}
	}
	if(num%8 !=0) fputc(holder, output); //catching an annoying edge case
	return;
}	
