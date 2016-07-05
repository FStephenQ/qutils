#include <stdio.h>
#include <stdlib.h>
#include "hamming.h"

//A very simple library of utilities related to calculating byte-level hamming weights

int hamming_weight(char c){
	int ret = 0;
	for(int i =7; i >=0; i--){ //Strongly depends on 8-bit byte (and 1 byte char)
		char tmp = c;
		tmp = (tmp >>i)&0x01; //move the (i+1)th bit to the lowest position, and & it with 0x01 (only lowest bit on) to negate all other remaining bits
		if(tmp == 1)
			ret++;
	}
	return ret;
}

int str_hamming_weight(char* c){
	char tmp = (c[0]);
	int i = 0;
	int ret = 0;
	while(tmp != '\0'){ //don't run off the end of the string
		ret += hamming_weight(tmp);
		tmp = (c[++i]);
	}
	return ret;
}

int int_hamming_weight(int c){
	int ret = 0;
	char* tmp = (char*)(&c); //All hail insane C pointer hacking!
	for(int i = 0; i < sizeof(int); i++){
		ret += hamming_weight(tmp[i]);
	}
	return ret;
}
		

int main(int argc, char* argv[]){ 
	if(sizeof(char) != 1){
		printf("You have a strange char size: %d. I can't handle this\n",sizeof(char));
		exit(1);
	}
	printf("Weight of 0x00: %d\n",hamming_weight(0));
	printf("Weight of A: %d\n",hamming_weight('A'));
	printf("Weight of b: %d\n",hamming_weight('b'));
	printf("Weight of 127: %d\n",hamming_weight(127));
	printf("Weight of 0xFF: %d\n",hamming_weight(0xFF));
	printf("Weight of \"Test\": %d\n",str_hamming_weight("Test"));
	printf("Weight of 0x0101: %d\n",str_hamming_weight("\x01\x01"));
	printf("Weight of 1000 %d\n",int_hamming_weight(1000));
	exit(0);
}
