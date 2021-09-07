#ifndef __PROCESADOR_H
#define __PROCESADOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tabla.h"
#include "macros.h"
#include "configuracion.h"

typedef enum {
    ESPECIES_EN_NEGATIVO,
    COTIZACION_COMPRA_VENTA,
} REPORTE;

typedef enum {
    CONSOLA,
    CSV,
    HTML
} FORMATO;

void listarEspeciesEnNegativo(FILE *fd, FORMATO formato);
void generarCotizacionesCompraYVenta(FILE *fd, FORMATO formato);

#endif