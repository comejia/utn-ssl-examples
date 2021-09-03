#ifndef __PROCESADOR_H
#define __PROCESADOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MEMORIA 1048576

typedef enum {
    ESPECIES_EN_NEGATIVO,
    COTIZACION_COMPRA_VENTA,
} REPORTE;

typedef enum {
    CONSOLA,
    CSV,
    HTML
} FORMATO;

FILE *leerPagina(char *fuente);
void cerrarPagina(FILE *fd);
void imprimirPagina(FILE *fd);
void generarReporte(FILE *fd, REPORTE reporte, FORMATO tipo);

#endif