#ifndef __PROCESADOR_H
#define __PROCESADOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char especie[8];
    char vencimiento[8];
    int cantNominalCompra;
    double precioCompra;
    double precioVenta;
    int cantNominalVenta;
    double ultimo;
    double variacion;
    double apertura;
    double min;
    double max;
    double cierreAnterior;
    long volumen;
    long monto;
    int operacion;
    char hora[12];
} t_registro;

typedef struct {
    int filas;
    int columnas;
    t_registro *regs;
} t_tabla;

typedef enum {
    CONSOLA,
    CSV,
    HTML
} FORMATO;

void listarEspeciesEnNegativoPor(FILE *fd, FORMATO formato);
void generarCotizacionesCompraYVenta(FILE *fd, FORMATO formato);

#endif