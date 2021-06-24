#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc < 3) {
        printf("Debe ingresar como parametros: <cadena_1> <cadena_2>\n");
        return 1;
    }

    char encriptacion[255];
    char *cadena1 = argv[1];
    char *cadena2 = argv[2];

    if(strlen(cadena1) != strlen(cadena2)) {
        printf("Las cadenas ingresadas deben tener la misma longitud.\n");
        return 1;
    }

    strcpy(encriptacion, cadena1);

    for(int i = 0; encriptacion[i] != '\0'; i++) {
        encriptacion[i] += cadena2[i];
    }

    printf("La palabra \"%s\" encriptada es: %s\n", cadena1, encriptacion);

    return 0;
}