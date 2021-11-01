#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

extern int yynerrs;
extern int yylexerrs;
extern FILE *yyin;

int main(int argc, char **argv) {
    if (argc > 2) {
        printf("Numero de parametros invalidos: <nombre_archivo>");
        return EXIT_FAILURE;
    }

    if (argc == 2) {
        //yyin = fopen(argv[1], "r");
        //FILE *archivo = fopen(argv[1], "r");
        //yyset_in(archivo);
    }

    yyparse();

    return EXIT_SUCCESS;
}