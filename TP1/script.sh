#!/bin/bash

# Comandos del punto 2

# a
sed 's/\./.\n/g' breve_historia.txt

# b
sed 's/\./.\n/g' breve_historia.txt | sed '/^\s*$/d'

# c
sed 's/\./.\n/g' breve_historia.txt | sed '/^\s*$/d' > breve_historia_2.txt

# d
grep -i --color 'guerra' breve_historia.txt

# e
grep --color -E '^A.*(s|s\.)$' breve_historia.txt

# f
grep --color -c 'peronismo' breve_historia.txt

# g
grep --color -E 'Sarmiento.*Rosas' breve_historia.txt

# h
grep --color -E '18[0-9]{2}' breve_historia.txt

# i
sed 's/^[a-zA-Z]*\b//g' breve_historia.txt

