#include <stdio.h>
#include <stdlib.h>
#include "hamming.h"

//A very simple library of utilities related to calculating byte-level hamming 
//Done in one of the least efficient manners possible

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

long void_hamming_weight(void* c, int len){
	int ret = 0;
	char* tmp = (char*)c;
	for(int i = 0; i < len; i++){
		ret += hamming_weight(tmp[i]);
	}
	return ret;
}

//Calculate the hamming distance between two bytes
int hamming_distance(char c1, char c2){
	return hamming_weight(c1^c2);
}


/*A set of test cases
int main(int argc, char* argv[]){ 
	if(sizeof(char) != 1){
		printf("You have a strange char size: %d. I can't handle this\n",sizeof(char));
		exit(1);
	}
	float t = 10.10;
	printf("Weight of 0x00: %d\n",hamming_weight(0));
	printf("Weight of A: %d\n",hamming_weight('A'));
	printf("Weight of b: %d\n",hamming_weight('b'));
	printf("Weight of 127: %d\n",hamming_weight(127));
	printf("Weight of 0xFF: %d\n",hamming_weight(0xFF));
	printf("Weight of \"Test\": %d\n",str_hamming_weight("Test"));
	printf("Weight of 0x0101: %d\n",str_hamming_weight("\x01\x01"));
	printf("Weight of 1000: %d\n",int_hamming_weight(1000));
	printf("Weight of 10.10: %d\n",void_hamming_weight(&t,sizeof(float)));
	printf("Distance between 0x00 and 0x01: %d\n",hamming_distance(0x00,0x01));
	printf("Distance between 0xFE and 0xFF: %d\n",hamming_distance(0xFE,0xFF));
	printf("Distance between 0xCA and 0x4D: %d\n",hamming_distance(0xCA,0x4D));
	exit(0);
}*/
