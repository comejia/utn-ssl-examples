#ifndef TABLA_SIMBOLOS_H_
#define TABLA_SIMBOLOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANIO_TABLA 100
#define LONGITUD_MAX_CARACTERES 32

typedef struct {
    char id[LONGITUD_MAX_CARACTERES];
    int valor;
} t_tabla_simbolos;

void iniciarTablaSimbolos(void);

void guardarValorEnTabla(char *simbolo, int valor);

void cargarEntradaEnTabla(char *simbolo);

int leerValorSimbolo(char *simbolo);

void imprimirTablaSimbolos(void);

// void init_TS(void);
// void EscribirATabla(char* s, int v);
// void cargarEntradas(char* p1); // para Leer(IDs);
// int ValorSimbolo(char* s);
// int IndiceTabla(char* s);

#endif