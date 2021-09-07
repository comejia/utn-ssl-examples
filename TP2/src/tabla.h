#ifndef __TABLA_H
#define __TABLA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATOS   16

typedef enum {
    ESPECIE = 0,
    VENCIMIENTO,
    CANT_NOMINAL_COMPRA,
    PRECIO_COMPRA,
    PRECIO_VENTA,
    CANT_NOMINAL_VENTA,
    ULTIMO,
    VARIACION,
    APERTURA,
    PRECIO_MIN,
    PRECIO_MAX,
    CIERRE_ANTERIOR,
    VOLUMEN,
    MONTO,
    OPERACION,
    HORA
} DATO;

// typedef struct {
//     char especie[8];
//     char vencimiento[8];
//     int cantNominalCompra;
//     double precioCompra;
//     double precioVenta;
//     int cantNominalVenta;
//     double ultimo;
//     double variacion;
//     double apertura;
//     double min;
//     double max;
//     double cierreAnterior;
//     long volumen;
//     long monto;
//     int operacion;
//     char hora[12];
// } t_registro;

typedef struct {
    char especie[16];
    char vencimiento[16];
    char cantNominalCompra[16];
    char precioCompra[16];
    char precioVenta[16];
    char cantNominalVenta[16];
    char ultimo[16];
    char variacion[16];
    char apertura[16];
    char min[16];
    char max[16];
    char cierreAnterior[16];
    char volumen[16];
    char monto[16];
    char operacion[16];
    char hora[16];
} t_registro;

typedef struct {
    int filas;
    t_registro *regs;
} t_tabla;

t_tabla *crearTabla();
void eliminarTabla(t_tabla *tabla);
void agregarRegistro(t_tabla *tabla);
void guardarDatoEnRegistro(t_registro *reg, DATO indice, char *dato);

#endif