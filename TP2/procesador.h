#ifndef __PROCESADOR_H
#define __PROCESADOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct {
//     char especie[8];
//     char vencimiento[8];
//     int cantNominalCompra;
//     double precioCompra;
//     double precioVenta;
//     int cantNominalVenta;
//     double ultimo;
//     double variacion;
//     double apertura;
//     double min;
//     double max;
//     double cierreAnterior;
//     long volumen;
//     long monto;
//     int operacion;
//     char hora[12];
// } t_registro;
typedef struct {
    char especie[16];
    char vencimiento[16];
    char cantNominalCompra[16];
    char precioCompra[16];
    char precioVenta[16];
    char cantNominalVenta[16];
    char ultimo[16];
    char variacion[16];
    char apertura[16];
    char min[16];
    char max[16];
    char cierreAnterior[16];
    char volumen[16];
    char monto[16];
    char operacion[16];
    char hora[16];
} t_registro;

typedef struct {
    int filas;
    //int columnas;
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