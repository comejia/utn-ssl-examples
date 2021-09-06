#include "procesador.h"

typedef enum {
    ESPECIES_EN_NEGATIVO,
    COTIZACION_COMPRA_VENTA,
} REPORTE;

static char pagina[1048576];

static void obtenerTabla(FILE *fd);
static void generarReporte(t_tabla *tabla, REPORTE reporte, FORMATO tipo);
static t_tabla *parsearTabla(char *pagina);
static void guardarDato(t_registro *regs, int indice, char *dato);


void listarEspeciesEnNegativoPor(FILE *fd, FORMATO formato) {
    t_tabla *tabla;
    obtenerTabla(fd);
    tabla = parsearTabla(pagina);
    generarReporte(tabla, ESPECIES_EN_NEGATIVO, formato);
}

void generarCotizacionesCompraYVenta(FILE *fd, FORMATO formato) {

}

static void generarReporte(t_tabla *tabla, REPORTE reporte, FORMATO tipo) {
    if(reporte == ESPECIES_EN_NEGATIVO && tipo == CONSOLA) {
        printf("\n\tEspecies en negativo\n");
        for (int i = 0; i < tabla->filas; i++) {            
            float val = strtof(tabla->regs[i].variacion, NULL);
            if(val < 0) {
                printf("Especie: %s, ", tabla->regs[i].especie);
                printf("variacion: %f\n", val);
            }
        }
    }
}

static void obtenerTabla(FILE *fd) {
    char line[4096];
    while(fgets(line, sizeof(line), fd) != NULL) {
        if(strstr(line, "<tbody>") == NULL) {
            continue;
        }
        break;
    }
    strcat(pagina, line);
    while(fgets(line, sizeof(line), fd) != NULL) {
        if(strstr(line, "</tbody>") != NULL) {
            break;
        }
        if(strstr(line, ">48hs<")) {
            strcat(pagina, line);
        }
        
    }
    strcat(pagina, line);
}

static t_tabla *parsearTabla(char *pagina) {
    t_tabla *tabla = (t_tabla *)malloc(sizeof(t_tabla));
    tabla->regs = NULL;
    tabla->filas = 0;
    char *aux = pagina;
    char *td = "<td";
    char *registro;
    
    char dato[16];
    int iDato = 0;
    int i;

    while ((registro = strstr(aux, td)) != NULL) {
        (tabla->filas)++;
        tabla->regs = realloc(tabla->regs, sizeof(t_registro) * tabla->filas);
        iDato = 0;
        while ((registro = strstr(aux, td)) != NULL && iDato < 16) {
            if(iDato != 7) {
                while (*registro++ != '>');
                for(i = 0; registro[i] != '<'; i++) {
                    if(registro[i] == ',') {
                        registro[i] = '.';
                    }
                    dato[i] = registro[i];
                }
            }
            else {
                while (*registro++ != '>');
                while (*registro++ != '>');
                for(i = 0; registro[i] != '%'; i++) {
                    if(registro[i] == ',') {
                        registro[i] = '.';
                    }
                    dato[i] = registro[i];
                }
            }
            dato[i] = '\0';
            guardarDato(&(tabla->regs[(tabla->filas)-1]), iDato, dato);
            aux = registro;
            iDato++;
        }
    }
    // printf("FILAS: %d\n", tabla->filas);
    // printf("DATO: %s\n", tabla->regs[1].variacion);
    // printf("DATO: %s\n", tabla->regs[4].variacion);

    return tabla;
}

static void guardarDato(t_registro *regs, int indice, char *dato) {
    switch(indice) {
        case 0:
            strcpy(regs->especie, dato);
            break;
        case 1:
            strcpy(regs->vencimiento, dato);
            break;
        case 2:
            strcpy(regs->cantNominalCompra, dato);
            break;
        case 3:
            strcpy(regs->precioCompra, dato);
            break;
        case 4:
            strcpy(regs->precioVenta, dato);
            break;
        case 5:
            strcpy(regs->cantNominalVenta, dato);
            break;
        case 6:
            strcpy(regs->ultimo, dato);
            break;
        case 7:
            strcpy(regs->variacion, dato);
            break;
        case 8:
            strcpy(regs->apertura, dato);
            break;
        case 9:
            strcpy(regs->min, dato);
            break;
        case 10:
            strcpy(regs->max, dato);
            break;
        case 11:
            strcpy(regs->cierreAnterior, dato);
            break;
        case 12:
            strcpy(regs->volumen, dato);
            break;
        case 13:
            strcpy(regs->monto, dato);
            break;
        case 14:
            strcpy(regs->operacion, dato);
            break;
        case 15:
            strcpy(regs->hora, dato);
            break;
    }
}