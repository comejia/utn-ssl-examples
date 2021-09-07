#ifndef __MENU_H
#define __MENU_H

#include <stdio.h>

typedef enum {
    LISTAR = 1,
    GENERAR_CSV,
    GENERAR_HTML,
    IMPRIMIR_CODIGO_FUENTE,
    SALIR = 0,
} OPCION;

void menu();

#endif