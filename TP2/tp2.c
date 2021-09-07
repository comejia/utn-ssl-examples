#include "tp2.h"

int main(int argc, char **argv)
{
    int opcion;
    char *fuente = NULL;
    TIPO_ARCHIVO tipo;

    if (argc < 2) {
        printf("Debe ingresar como parametro: --offline | --online\n");
        return EXIT_FAILURE;
    }

    if(strcmp(argv[1], "--online") == 0) {
        fuente = "wget -q -O- https://bolsar.info/lideres.php --no-check-certificate";
        tipo = PIPE_STREAM;
    } else {
        fuente = "bolsar.html";
        tipo = STREAM;
    }

    do
    {
        menu();
        printf("Ingresar opcion: ");
        scanf("%d", &opcion);
        ejecutarOpcion((OPCION) opcion, fuente, tipo);
    } while (opcion != SALIR);

    return EXIT_SUCCESS;
}


void ejecutarOpcion(OPCION opcion, char *fuente, TIPO_ARCHIVO tipo) {
    FILE *fd = leerPagina(fuente, tipo);

    switch (opcion) {
        case LISTAR:
            listarEspeciesEnNegativo(fd, CONSOLA);
            break;
        case GENERAR_CSV:
            generarCotizacionesCompraYVenta(fd, CSV);
            printf("\nReporte generado con exito. Abra el archivo 'compra_venta.csv' para ver su contenido.\n");
            break;
        case GENERAR_HTML:
            listarEspeciesEnNegativo(fd, HTML);
            printf("\nReporte generado con exito. Abra el archivo 'index.html' para ver su contenido.\n");
            break;
        case IMPRIMIR_CODIGO_FUENTE:
            imprimirPagina(fd);
            break;
        case SALIR:
            printf("\nSaliendo de la aplicacion...\n");
            break;
        default:
            printf("\nLa opcion seleccionada no es valida. Ingresa otra opción\n");
    }

    cerrarPagina(fd, tipo);
}
