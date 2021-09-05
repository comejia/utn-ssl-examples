#include "procesador.h"

typedef enum {
    ESPECIES_EN_NEGATIVO,
    COTIZACION_COMPRA_VENTA,
} REPORTE;

static char pagina[1048576];

static void obtenerTabla(FILE *fd);
static void generarReporte(t_tabla *tabla, REPORTE reporte, FORMATO tipo);
static t_tabla *parsearTabla(char *pagina);


void listarEspeciesEnNegativoPor(FILE *fd, FORMATO formato) {
    t_tabla *tabla;
    obtenerTabla(fd);
    tabla = parsearTabla(pagina);
    generarReporte(tabla, ESPECIES_EN_NEGATIVO, formato);
}

void generarCotizacionesCompraYVenta(FILE *fd, FORMATO formato) {

}

static void generarReporte(t_tabla *tabla, REPORTE reporte, FORMATO tipo) {

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
        if (strstr(line, ">48hs<")) {
            strcat(pagina, line);
        }
        
    }
    strcat(pagina, line);
    //printf("TABLA: %s", pagina);
}

static t_tabla *parsearTabla(char *pagina) {
    t_tabla *tabla = malloc(sizeof(t_tabla));
    return tabla;
}

