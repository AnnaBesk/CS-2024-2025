#!/bin/bash

export DYLD_LIBRARY_PATH=external/lib:$DYLD_LIBRARY_PATH

./program

unset DYLD_LIBRARY_PATH