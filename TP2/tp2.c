#include "tp2.h"

int main(int argc, char **argv)
{
    int opcion;
    FILE *fd;
    TIPO_ARCHIVO tipo;

    if (argc < 2) {
        printf("Debe ingresar como parametro: --offline | --online\n");
        return EXIT_FAILURE;
    }

    if(strcmp(argv[1], "--online") == 0) {
        fd = leerPagina("wget -q -O- https://bolsar.info/lideres.php --no-check-certificate", PIPE_STREAM);
        tipo = PIPE_STREAM;
    } else {
        fd = leerPagina("bolsar.html", STREAM);
        tipo = STREAM;
    }
    
    //imprimirPagina(fd);

    do
    {
        menu();
        printf("Ingresar opcion: ");
        scanf("%d", &opcion);
        ejecutarOpcion((OPCION) opcion, fd);
    } while (opcion != SALIR);
    
    cerrarPagina(fd, tipo);

    return EXIT_SUCCESS;
}


void ejecutarOpcion(OPCION opcion, FILE *fd) {
    switch (opcion) {
        case LISTAR:
            listarEspeciesEnNegativo(fd, CONSOLA);
            break;
        case GENERAR_CSV:
            generarCotizacionesCompraYVenta(fd, CSV);
            break;
        case GENERAR_HTML:
            listarEspeciesEnNegativo(fd, HTML);
            break;
        case SALIR:
            printf("Saliendo de la aplicacion...\n");
            break;
        default:
            printf("La opcion seleccionada no es valida. Ingresa una opcion valida\n");
    }
}
