#include "tp2.h"

int main(int argc, char **argv)
{
    int opcion;
    FILE *fd;

    if (argc < 2) {
        printf("Debe ingresar como parametro: --offline o --online\n");
        return EXIT_FAILURE;
    }

    fd = leerPagina(argv[1]);
    
    imprimirPagina(fd);

    do
    {
        menu();
        printf("Ingresar opcion: ");
        scanf("%d", &opcion);
        ejecutarOpcion((OPCION) opcion, fd);
    } while (opcion != SALIR);
    
    cerrarPagina(fd);
    return EXIT_SUCCESS;
}


void ejecutarOpcion(OPCION opcion, FILE *fd) {
    switch (opcion) {
        case LISTAR_EN_PANTALLA:
            generarReporte(fd, ESPECIES_EN_NEGATIVO, CONSOLA);
            break;
        case GENERAR_CSV:
            generarReporte(fd, COTIZACION_COMPRA_VENTA, CSV);
            break;
        case GENERAR_HTML:
            generarReporte(fd, ESPECIES_EN_NEGATIVO, HTML);
            break;
        case SALIR:
            printf("Saliendo de la aplicacion...\n");
            break;
        default:
            printf("La opcion seleccionada no es valida. Ingresa una opcion valida\n");
    }
}