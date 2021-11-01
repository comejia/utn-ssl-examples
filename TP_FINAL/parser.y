%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "scanner.h"

    void yyerror(const char *s);
%}

%defines "parser.h"
%output "parser.c"

%union {
    int numero;
}

%token FDT INICIO FIN ID
%token ASIGNACION PUNTOYCOMA PARENIZQUIERDO PARENDERECHO COMA
%token SUMA RESTA
%token LEER ESCRIBIR
%token <numero> CONSTANTE

%start objetivo

%%
// <objetivo>  ->  <programa>  FDT
objetivo:
    programa FDT
    ;

// <programa>  ->  INICIO  <listaSentencias>  FIN
programa:
    INICIO listaSentencias FIN
    ;

// <listaSentencias>  ->  <sentencia>  {<sentencia>}
listaSentencias:
    sentencia 
    | listaSentencias sentencia
    ;

// <sentencia>  ->  ID  ASIGNACIÓN  <expresión>  PUNTOYCOMA  |
//      LEER  PARENIZQUIERDO  <listaIdentificadores>  PARENDERECHO  PUNTOYCOMA  |
//      ESCRIBIR  PARENIZQUIERDO  <listaExpresiones>  PARENDERECHO  PUNTOYCOMA
sentencia:
    ID ASIGNACION expresion PUNTOYCOMA                                              { printf("Sentencia asignacion\n"); }
    | LEER PARENIZQUIERDO listaIdentificadores PARENDERECHO PUNTOYCOMA              { printf("Sentencia leer\n"); }
    | ESCRIBIR PARENIZQUIERDO listaExpresiones PARENDERECHO PUNTOYCOMA              { printf("Sentencia escribir\n"); }
    ;

// <listaIdentificadores>  ->  ID  {COMA  ID}
listaIdentificadores:
    ID 
    | listaIdentificadores COMA  ID
    ;

// <listaExpresiones>  ->  <expresión>  {COMA  <expresión>}
listaExpresiones:
    expresion 
    | listaExpresiones COMA expresion
    ;

// <expresión>  ->  <primaria>  {<operadorAditivo>  <primaria>}
expresion:
    primaria 
    | expresion operadorAditivo primaria
    ;

// <primaria>  ->  ID  |  CONSTANTE  | PARENIZQUIERDO  <expresión>  PARENDERECHO
primaria:
    ID
    | CONSTANTE
    | PARENIZQUIERDO expresion PARENDERECHO
    ;

// <operadorAditivo>  ->  SUMA | RESTA
operadorAditivo:
    SUMA
    | RESTA
    ;

%%


// void yyerror(const char *s){ // si no hubiese estado definido, directamente el yyerror imprimiría: "syntax error" solamente
//     printf("Línea #%d: %s\n", yylineno, s);
//     return;
// }

void yyerror(const char *s) {
  printf("Error en la expresion. %s\n", s);
}
