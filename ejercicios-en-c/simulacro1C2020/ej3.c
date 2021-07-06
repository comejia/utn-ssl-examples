#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc < 3) {
        printf("Debe ingresar como parametros: <palabra a buscar> <ruta archivo>\n");
        return 1;
    }

    char texto[255];
    int contadorPalabraBuscada = 0;
    char *palabraABuscar = argv[1];
    char *rutaArchivo = argv[2];

    FILE *archivo = fopen(rutaArchivo, "r");

    while (fscanf(archivo, "%s", texto) != EOF) {
        if(strcmp(palabraABuscar, texto) == 0) {
            contadorPalabraBuscada++;
        }
    }

    printf("La palabra \"%s\" aparece %d veces\n", palabraABuscar, contadorPalabraBuscada);

    fclose(archivo);

    return 0;
}