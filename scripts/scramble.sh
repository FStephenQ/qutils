#!/bin/bash

#A stupid little program to convert an input file into a fairly highly random string.
cat $1 | xor - - | binary_convert d - - | invert - > m; file_weight m > q; xor $1 q | xor - - | xor m - | xor $1 m | xor - -
rm q m
