%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "scanner.h"
    #define YYSTYPE int

    void yyerror(const char *s);
%}

%defines "parser.h"
%output "parser.c"

/* %union {
    //char *cadena;
    int numero;
} */

%token FDT INICIO FIN ID
//%token <cadena> ID
%token ASIGNACION PUNTOYCOMA PARENIZQUIERDO PARENDERECHO COMA
%token SUMA RESTA
%token LEER ESCRIBIR
%token CONSTANTE

%left SUMA RESTA
%right ASIGNACION

//%type <numero> expresion primaria operadorAditivo

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
    ID ASIGNACION expresion PUNTOYCOMA                                      { printf("Sentencia asignacion (valor = %d)\n", $3); }
    | LEER PARENIZQUIERDO listaIdentificadores PARENDERECHO PUNTOYCOMA      { printf("Sentencia leer\n"); }
    | ESCRIBIR PARENIZQUIERDO listaExpresiones PARENDERECHO PUNTOYCOMA      { printf("Sentencia escribir\n"); }
    ;

// <listaIdentificadores>  ->  ID  {COMA  ID}
listaIdentificadores:
    ID
    | listaIdentificadores COMA ID
    ;

// <listaExpresiones>  ->  <expresión>  {COMA  <expresión>}
listaExpresiones:
    expresion                                                               { printf("Resultado %d\n", $1); }
    | listaExpresiones COMA expresion                                       { printf("Resultado %d\n", $3); }
    ;

// <expresión>  ->  <primaria>  {<operadorAditivo>  <primaria>}
expresion:
    primaria                                                                { $$ = $1; }
    | expresion operadorAditivo primaria                                    { $$ = $2 == '+' ? $1 + $3 : $1 - $3; }

// <primaria>  ->  ID  |  CONSTANTE  | PARENIZQUIERDO  <expresión>  PARENDERECHO
primaria:
    ID                                                                      { $$ = 0; } //{ $$ = atoi($1); } //no deveuelve el valor del identificador
    | CONSTANTE                                                             { $$ = $1; }
    | PARENIZQUIERDO expresion PARENDERECHO                                 { $$ = $2; }
    ;

// <operadorAditivo>  ->  SUMA | RESTA
operadorAditivo:
    SUMA                                                                    { $$ = '+'; }
    | RESTA                                                                 { $$ = '-'; }
    ;

%%


void yyerror(const char *s) {
  printf("Error en la expresion. %s\n", s);
}
