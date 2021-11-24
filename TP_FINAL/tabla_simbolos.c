#include "tabla_simbolos.h"


t_tabla_simbolos ts[TAMANIO_TABLA];


int buscarEnTabla(const char *a_buscar) {
    for (int indice = 0; indice < TAMANIO_TABLA; indice++) {
        if (strcmp(ts[indice].id, a_buscar) == 0) {
            return indice;
        }
    }
    return -1;
}

void cargarEntrada(char *simbolo, int valor) {
    int indice = buscarEnTabla(ENTRADA_VACIA);
    if (indice == -1) {
        printf("No hay espacio en la tabla de simbolo.\n");
        return;
    }
    strcpy(ts[indice].id, simbolo);
    ts[indice].valor = valor;
}



void iniciarTablaSimbolos(void) {
    for (int i = 0; i < TAMANIO_TABLA; i++) {
        strcpy(ts[i].id, ENTRADA_VACIA);
    }
}

void guardarValorEnTabla(char *simbolo, int valor) {
    int indice = buscarEnTabla(simbolo);
    if (indice == -1) {
        cargarEntrada(simbolo, valor);
    } else {
        ts[indice].valor = valor;
    }
}

void cargarEntradaEnTabla(char *simbolo) {
    int valor;
    printf("Ingrese valor de '%s': ", simbolo);
    if(scanf("%d", &valor) != 1) {
        printf("El valor ingresado para '%s' no es un numero valido\n", simbolo);
        exit(EXIT_FAILURE);
    }
    guardarValorEnTabla(simbolo, valor);
}

int leerValorSimbolo(char *simbolo) {
    int indice = buscarEnTabla(simbolo);
    if (indice == -1) {
        printf("No hay valor asignado para: '%s'.\n", simbolo);
        exit(EXIT_FAILURE);
    }
    return ts[indice].valor;
}

void imprimirTablaDeSimbolos(void) {
    printf("\n\n\t\t TABLA DE SIMBOLOS\n");
    for (int i = 0; i < TAMANIO_TABLA; i++) {
        if (strcmp(ts[i].id, ENTRADA_VACIA) != 0) {
            printf("%s := %d\n", ts[i].id, ts[i].valor);
        }
    }
    printf("\n");
}
