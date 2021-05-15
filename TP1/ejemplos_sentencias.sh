#!/bin/bash

NOMBRE=Pepe
if [ $NOMBRE == "Pepe"  ]; then
	echo "Es Pepe"
fi

NOMBRE=Carlos
if [ $NOMBRE == "Pepe" ]; then
	echo "Es Pepe"
else
	echo "No es Pepe"
fi

NOMBRE=Carolina
if [ $NOMBRE == "Pepe" ]; then
	echo "Es Pepe"
elif [ $NOMBRE == "Carlos" ]; then
	echo "Es Carlos"
else
	echo "No es Pepe ni Carlos"
fi


NOMBRE=Andrea
case $NOMBRE in
	"Pepe")
		echo "Es Pepe"
		;;
	"Carlos")
		echo "Es Carlos"
		;;
	"Carolina")
		echo "Es Carolina"
		;;
	*)
		echo "No es un nombre conocido"
		;;
	"Andrea")
		echo "Es Andrea"
		;;
esac

for i in {1..5}
do
	echo "Numero $i"
done

for (( i=1; i<=5; i++ ))
do
	echo "Numero $i"
done


i=1
while [ $i -le 5 ]
do
	echo "Numero $i"
	i=$((i+1))
done


mi_funcion() {
	echo "Recibido: $1"
	echo "Recibido: $2"
}


mi_funcion "hola" 3


sumar() {
	SUMA=$(($1+$2))
}

sumar 2 4

echo "La suma es: $SUMA"


sumar_numeros() {
	local resultado=$(($1+$2))
	echo "$resultado"
}

RES=$(sumar_numeros 2 5)

echo "La suma es: $RES"




