%{
    #include <stdio.h>
    #include <string.h>
    #include "parser.h"
%}


%option header-file="scanner.h"
%option outfile="scanner.c"
%option noinput
%option nounput

digito                  [0-9]
letra                   [a-zA-Z]
identificador           {letra}({letra}|{digito})*
constante               {digito}+
espacio                 [ \t\n]+

%%

inicio                  return INICIO;
fin                     return FIN;
leer                    return LEER;
escribir                return ESCRIBIR;

{identificador}         return ID;
{constante}             return CONSTANTE;

"("                     return PARENIZQUIERDO;
")"                     return PARENDERECHO;
";"                     return PUNTOYCOMA;
","                     return COMA;
"+"                     return SUMA;
"-"                     return RESTA;
":="                    return ASIGNACION;
"?"                     return FDT;
{espacio}               ;

%%

int yywrap(void) {
    return 1;
}