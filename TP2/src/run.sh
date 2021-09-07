#!/bin/bash

if [ -z $1 ]; then
    echo "Precaucion! El programa requiere al menos un parametro"
fi

gcc *.c -o tp2 -Wall
./tp2 $1