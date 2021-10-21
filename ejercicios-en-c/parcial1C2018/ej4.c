#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc < 3) {
        printf("Debe ingresar como parametros: <ruta_archivo_1> <ruta_archivo_2>\n");
        return 1;
    }

    char texto[255];
    char *rutaArchivo1 = argv[1];
    char *rutaArchivo2 = argv[2];

    FILE *archivo1 = fopen(rutaArchivo1, "r");
    FILE *archivo2 = fopen(rutaArchivo2, "a");

    while(fgets(texto, 255, archivo1) != NULL) {
        //char *aux = texto;
        /*while((aux = strchr(aux, 'a')) != NULL) { // otra solucion
            aux[0] = 'e';
        }*/

        for(int i = 0; texto[i] != '\0'; i++) {
            if(texto[i] == 'a') {
                texto[i] = 'e';
            }
        }

        fprintf(archivo2, "%s", texto);
    }

    fclose(archivo1);
    fclose(archivo2);

    return 0;
}