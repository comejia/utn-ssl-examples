#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "scanner.h"

extern int yynerrs;
extern int yylexerrs;

int main(int argc, char **argv) {
    if (argc > 2) {
        printf("Numero de parametros invalidos: <nombre_archivo>");
        return EXIT_FAILURE;
    }

    if (argc == 2) {
        printf("Ingreso de datos desde: %s\n", argv[1]);
        FILE *archivo = fopen(argv[1], "r");
        yyset_in(archivo);
    } else {
        printf("Ingreso de datos desde consola\n");
    }

    yyparse();

    return EXIT_SUCCESS;
}