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
#include "bin2ascii.h"



/*******************************
 * For our purposes, encoding
 * refers to converting binary
 * data into an ascii string of
 * 1's and 0's...
 ********************************/

void bin2ascii(FILE *input,FILE *output){
	//char hex[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	while(1){
		int x = fgetc(input);
		if(x==EOF)break;
		int num;
		int hold = 0;
		for(num = 0; num<8;num++){
			if((char)(x<<num)>>8){ //fun bit-shifting
			/*	if(flag == 'h'){ //future functionality will add support for hexidecimal encoding
					hold+=(num%4)*2;
					if(!(num%4)) hold+=1;
				}
				else */
					fputc('1', output);
			}
			else{
				//if(flag!='h')
					fputc('0',output);
			}
			/*if(flag == 'h'&&(num == 3 || num == 7)){
				fputc(hex[hold], output);
				hold = 0;
			}*/
		}
	}
	return;
}

//... And decoding refers to the inverse.

void ascii2bin(FILE *input,FILE *output){
	unsigned char holder = 0;
	int num = 0;
	while(1){
		int x = fgetc(input);
		if(x == EOF) break;
		holder <<= 1;
		if(x >= '1'){
			holder = holder | 0x01; //bitwise opperations are *fun*.
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
