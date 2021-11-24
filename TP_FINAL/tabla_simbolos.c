#include "tabla_simbolos.h"

t_tabla_simbolos ts[TAMANIO_TABLA];

int buscarSimbolo(char *simbolo) {
    for (int i = 0; i < TAMANIO_TABLA; i++) {
        if (strcmp(simbolo, ts[i].id) == 0) {
            return i;
        }
    }
    return -1;
}

void cargarEntrada(char *simbolo, int valor) {
    int indice;
    for (indice = 0; indice < TAMANIO_TABLA; indice++) {
        if (strcmp(ts[indice].id, "") == 0) {
            break;
        }
    }
    if (indice == TAMANIO_TABLA) {
        printf("No hay espacio en la tabla de simbolo\n");
        return;
    }
    sprintf(ts[indice].id, "%s", simbolo);
    ts[indice].valor = valor;
}



void iniciarTablaSimbolos(void) {
    for (int i = 0; i < TAMANIO_TABLA; i++) {
        strcpy(ts[i].id, "");
    }
}

void guardarValorEnTabla(char *simbolo, int valor) {
    //printf("Simbolo: %s, valor %d\n", simbolo, valor);
    int indice = buscarSimbolo(simbolo);
    //printf("Indice: %d\n", indice);
    if (indice == -1) {
        //printf("El simbolo no esta en la tabla\n");
        cargarEntrada(simbolo, valor);
    } else {
        ts[indice].valor = valor;
    }
}

void cargarEntradaEnTabla(char *simbolo) {
    int valor;
    //char aux[20];
    printf("Ingrese valor de %s: ", simbolo);
    scanf("%d", &valor);
    guardarValorEnTabla(simbolo, valor);
}

int leerValorSimbolo(char *simbolo) {
    int indice = buscarSimbolo(simbolo);
    if (indice == -1) {
        printf("No hay valor asignado para simbolo '%s'.\n", simbolo);
        exit(EXIT_FAILURE);
    }
    return ts[indice].valor;
}

void imprimirTablaSimbolos(void) {
    printf("\n\n\t\t TABLA DE SIMBOLOS\n");
    for (int i = 0; i < TAMANIO_TABLA; i++) {
        if (strcmp(ts[i].id, "")) {
            printf("%s := %d\n", ts[i].id, ts[i].valor);
        }
    }
}