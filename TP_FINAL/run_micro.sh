#!/bin/bash

bison parser.y
flex scanner.l

gcc *.c -o micro -Wall

echo "Ejecutando Lenguaje micro..."
./micro $1