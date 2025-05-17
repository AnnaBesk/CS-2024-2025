#!/bin/bash

gcc -DUPPERCASE -c alice.c -o alice.o
gcc -c bob.c -o bob.o
gcc -c main.c -o main.o

gcc alice.o bob.o main.o
./a.out