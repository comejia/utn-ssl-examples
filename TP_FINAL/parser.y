%{
    #include <stdio.h>
    #include <stdlib.h>
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
    sentencia {sentencia}
    ;

// <sentencia>  ->  ID  ASIGNACIÓN  <expresión>  PUNTOYCOMA  |
//      LEER  PARENIZQUIERDO  <listaIdentificadores>  PARENDERECHO  PUNTOYCOMA  |
//      ESCRIBIR  PARENIZQUIERDO  <listaExpresiones>  PARENDERECHO  PUNTOYCOMA
sentencia:
    ID ASIGNACION expresion PUNTOYCOMA                                              { printf("Sentencia asignacion\n") }
    | LEER PARENIZQUIERDO listaIdentificadores PARENDERECHO PUNTOYCOMA              { printf("Sentencia leer\n") }
    | ESCRIBIR PARENIZQUIERDO listaExpresiones PARENDERECHO PUNTOYCOMA              { printf("Sentencia escribir\n") }
    ;

// <listaIdentificadores>  ->  ID  {COMA  ID}
listaIdentificadores:
    ID {COMA  ID}
    ;

// <listaExpresiones>  ->  <expresión>  {COMA  <expresión>}
listaExpresiones:
    expresion {COMA expresion}
    ;

// <expresión>  ->  <primaria>  {<operadorAditivo>  <primaria>}
expresion:
    primaria {operadorAditivo primaria}
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




