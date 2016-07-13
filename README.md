# qutils
A set of very simple command-line utility programs, libraries, and scripts

#Scripts:
genrand.sh: Outputs a random base-64 string, which encodes an argument-length string of random bytes

#Libraries:

hamming: A set of utility functions for calculating hamming weights 

bin2ascii: A simple library for converting binary data to strings of ASCII 1's and 0's, and vice-versa. Considered silly

#Programs:
xor: XOR's its two arguments together, character-by-character, and outputs the result to stdout

binary_convert: Thin client for bin2ascii library

file_weight: A simple program to calculate the hamming weight of a given file (i.e. its hamming distance from the empty file)
