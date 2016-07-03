#!/bin/sh
head -c $1 /dev/urandom | base64
