#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc < 3) {
        printf("Debe ingresar como parametros: <palabra_a_buscar> <ruta_archivo>\n");
        return 1;
    }

    char texto[255];
    int contadorPalabraEncontrada = 0;
    char *palabraABuscar = argv[1];
    char *rutaArchivo = argv[2];

    FILE *archivo = fopen(rutaArchivo, "r");

    while (fscanf(archivo, "%s", texto) != EOF) {
        if(strcmp(palabraABuscar, texto) == 0) {
            contadorPalabraEncontrada++;
        }
    }

    printf("La palabra \"%s\" aparece %d veces\n", palabraABuscar, contadorPalabraEncontrada);

    fclose(archivo);

    return 0;
}