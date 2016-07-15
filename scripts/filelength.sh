#!/bin/sh
ls -l $1 | cut -f 5 -d ' '
