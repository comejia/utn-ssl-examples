#include "procesador.h"

char pagina[TAM_MEMORIA];

typedef enum {
    STREAM,
    PIPE_STREAM,
} TIPO_ARCHIVO;

static TIPO_ARCHIVO archivo;

FILE *leerPagina(char *fuente) {
    FILE *fd;
    if(strcmp(fuente, "--online") == 0) {
        fd = popen("wget -q -O- https://bolsar.info/lideres.php --no-check-certificate", "r");
        archivo = PIPE_STREAM;
    } else {
        fd = fopen("bolsar.html", "r");
        archivo = STREAM;
    }

    return fd;
}

void imprimirPagina(FILE *fd) {
    while(fgets(pagina, sizeof(pagina), fd) != NULL) {
        printf("%s\n", pagina);
    }
}

void generarReporte(FILE *fd, REPORTE reporte, FORMATO tipo) {

}

void cerrarPagina(FILE *fd) {
    if (archivo == STREAM)
        fclose(fd);
    else
        pclose(fd);
}