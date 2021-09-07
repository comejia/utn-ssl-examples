#include "pagina.h"

FILE *leerPagina(char *fuente, TIPO_ARCHIVO tipo) {
    FILE *fd = NULL;
    switch(tipo) {
        case PIPE_STREAM:
            fd = popen(fuente, "r");
            break;
        case STREAM:
            fd = fopen(fuente, "r");
            break;
        default:
            printf("Tipo de archivo invalido");
    }

    return fd;
}

void imprimirPagina(FILE *fd) {
    char pagina[TAM_MEMORIA];
    while(fgets(pagina, sizeof(pagina), fd) != NULL) {
        printf("%s\n", pagina);
    }
}

void cerrarPagina(FILE *fd, TIPO_ARCHIVO tipo) {
    if (tipo == PIPE_STREAM)
        pclose(fd);
    else
        fclose(fd);
}