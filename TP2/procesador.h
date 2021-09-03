#ifndef __PROCESADOR_H
#define __PROCESADOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    CONSOLA,
    CSV,
    HTML
} FORMATO;

void listarEspeciesEnNegativoPor(FILE *fd, FORMATO formato);
void generarCotizacionesCompraYVenta(FILE *fd, FORMATO formato);

#endif