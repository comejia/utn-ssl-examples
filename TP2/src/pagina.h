#ifndef __PAGINA_H
#define __PAGINA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MEMORIA 1048576 // 1M

typedef enum {
    STREAM,
    PIPE_STREAM,
} TIPO_ARCHIVO;


FILE *leerPagina(char *fuente, TIPO_ARCHIVO tipo);
void imprimirPagina(FILE *fd);
void cerrarPagina(FILE *fd, TIPO_ARCHIVO tipo);

#endif