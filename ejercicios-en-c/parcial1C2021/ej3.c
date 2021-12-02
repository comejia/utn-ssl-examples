#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *obtenerPalabra(char *linea, int posicion);

int main(int argc, char *argv[])
{
    if(argc < 3) {
        printf("Debe ingresar como parametros: <nombre_archivo> <posicion>\n");
        return 1;
    }

    char texto[512];
    int contadorPalabra = 0;
    char *nombreArchivo = argv[1];
    char *posicion = argv[2];
    char *palabra = NULL;

    FILE *archivo = fopen(nombreArchivo, "r");
    
    if(fgets(texto, 512, archivo) != NULL) {
        palabra = obtenerPalabra(texto, atoi(posicion));
        if(palabra != NULL) {
            contadorPalabra++;
        }
    }

    while (fscanf(archivo, "%s", texto) != EOF) {
        if(strcmp(palabra, texto) == 0) {
            contadorPalabra++;
        }
    }

    printf("La palabra encontrada es \"%s\" y aparece %d veces\n", palabra, contadorPalabra);

    fclose(archivo);

    return 0;
}

char *obtenerPalabra(char *linea, int posicion) {
    char *token = strtok(linea, " ");
    int contador = 0;
    while(token != NULL) {
        contador++;
        if(contador == posicion) {
            return token;
        }
        token = strtok(NULL, " ");
    }

    return NULL;
}