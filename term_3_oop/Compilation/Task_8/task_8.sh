#!/bin/bash

gcc -c alice.c -o alice.o
gcc -c bob.c -o bob.o

ar rcs libhouse.a alice.o bob.o