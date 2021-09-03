#include "pagina.h"

char pagina[TAM_MEMORIA];


FILE *leerPagina(char *fuente, TIPO_ARCHIVO tipo) {
    FILE *fd = NULL;
    switch(tipo) {
        case PIPE_STREAM:
            fd = popen("wget -q -O- https://bolsar.info/lideres.php --no-check-certificate", "r");
            break;
        case STREAM:
            fd = fopen("bolsar.html", "r");
            break;
        default:
            printf("Tipo de archivo invalido");
    }

    return fd;
}

void imprimirPagina(FILE *fd) {
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