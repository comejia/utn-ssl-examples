#include "tabla.h"

t_tabla *crearTabla() {
    t_tabla *tabla = (t_tabla *)malloc(sizeof(t_tabla));
    tabla->regs = NULL;
    tabla->filas = 0;
    return tabla;
}

void eliminarTabla(t_tabla *tabla) {
    for (int i = 0; i < tabla->filas; i++){
        free(&(tabla->regs[i]));
    }
    free(tabla);
}

void agregarRegistro(t_tabla *tabla) {
        (tabla->filas)++;
        tabla->regs = realloc(tabla->regs, sizeof(t_registro) * tabla->filas);
}

void guardarDatoEnRegistro(t_registro *reg, DATO indice, char *dato) {
    //t_registro *aux = &(tabla->regs[(tabla->filas)-1]);
    switch(indice) {
        case ESPECIE:
            strcpy(reg->especie, dato);
            break;
        case VENCIMIENTO:
            strcpy(reg->vencimiento, dato);
            break;
        case CANT_NOMINAL_COMPRA:
            strcpy(reg->cantNominalCompra, dato);
            break;
        case PRECIO_COMPRA:
            strcpy(reg->precioCompra, dato);
            break;
        case PRECIO_VENTA:
            strcpy(reg->precioVenta, dato);
            break;
        case CANT_NOMINAL_VENTA:
            strcpy(reg->cantNominalVenta, dato);
            break;
        case ULTIMO:
            strcpy(reg->ultimo, dato);
            break;
        case VARIACION:
            strcpy(reg->variacion, dato);
            break;
        case APERTURA:
            strcpy(reg->apertura, dato);
            break;
        case PRECIO_MIN:
            strcpy(reg->min, dato);
            break;
        case PRECIO_MAX:
            strcpy(reg->max, dato);
            break;
        case CIERRE_ANTERIOR:
            strcpy(reg->cierreAnterior, dato);
            break;
        case VOLUMEN:
            strcpy(reg->volumen, dato);
            break;
        case MONTO:
            strcpy(reg->monto, dato);
            break;
        case OPERACION:
            strcpy(reg->operacion, dato);
            break;
        case HORA:
            strcpy(reg->hora, dato);
            break;
        default:
            printf("ERROR: dato '%s' no pertenece a la tabla\n", dato);
    }
}