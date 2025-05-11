#!/bin/bash

gcc -fPIC -c alice.c bob.c
gcc -dynamiclib -o libhouse.dylib alice.o bob.o
rm -f alice.o bob.o