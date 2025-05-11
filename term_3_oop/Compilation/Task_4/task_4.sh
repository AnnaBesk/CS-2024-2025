#!/bin/bash
gcc -E hello.c -o hello.i
gcc -S -masm=intel hello.c
gcc -c hello.c
gcc hello.c -o hello