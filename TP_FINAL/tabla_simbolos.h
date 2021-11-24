#ifndef TABLA_SIMBOLOS_H_
#define TABLA_SIMBOLOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define TAMANIO_TABLA               100
#define LONGITUD_MAX_CARACTERES     32
#define ENTRADA_VACIA               ""

typedef struct {
    char id[LONGITUD_MAX_CARACTERES];
    int valor;
} t_tabla_simbolos;

void iniciarTablaSimbolos(void);

void guardarValorEnTabla(char *simbolo, int valor);

void cargarEntradaEnTabla(char *simbolo);

int leerValorSimbolo(char *simbolo);

void imprimirTablaDeSimbolos(void);

#endif