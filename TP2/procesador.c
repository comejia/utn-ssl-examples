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
    t_tabla *tabla;
    obtenerTabla(fd);
    tabla = parsearTabla(pagina);
    generarReporte(tabla, COTIZACION_COMPRA_VENTA, formato);
}

static void generarReporte(t_tabla *tabla, REPORTE reporte, FORMATO tipo) {
    if(reporte == ESPECIES_EN_NEGATIVO && tipo == CONSOLA) {
        printf("\n\tEspecies en negativo\n");
        printf(HEADER_CONSOLA);
        for (int i = 0; i < tabla->filas; i++) {            
            float val = strtof(tabla->regs[i].variacion, NULL);
            if(val < 0) {
                printf(FORMATO_FILA_CONSOLA, 
                    tabla->regs[i].especie, tabla->regs[i].vencimiento, tabla->regs[i].cantNominalCompra, tabla->regs[i].precioCompra, tabla->regs[i].precioVenta, tabla->regs[i].cantNominalVenta, tabla->regs[i].ultimo, tabla->regs[i].variacion,
                    tabla->regs[i].apertura, tabla->regs[i].min, tabla->regs[i].max, tabla->regs[i].cierreAnterior, tabla->regs[i].volumen, tabla->regs[i].monto, tabla->regs[i].operacion, tabla->regs[i].hora
                );
            }
        }
    }

    if(reporte == COTIZACION_COMPRA_VENTA && tipo == CSV) {
        FILE *file = fopen("compra_venta.csv", "w");
        fprintf(file, HEADER_CSV);
        for (int i = 0; i < tabla->filas; i++) {
            fprintf(file, FORMATO_FILA_CSV,
                tabla->regs[i].especie, tabla->regs[i].precioCompra, tabla->regs[i].precioVenta, tabla->regs[i].apertura, tabla->regs[i].min, tabla->regs[i].max
            );
        }
    }

    if(reporte == ESPECIES_EN_NEGATIVO && tipo == HTML) {
        FILE *template = fopen("template.html", "r");
        FILE *html = fopen("index.html", "w");
        char buf[4096] = {0};
        char linea[512] = {0};
        while(fgets(linea, sizeof(linea), template) != NULL) {
            strcat(buf, linea);
        }
        char fila[2048] = {0};
        char filas[4096] = {0};

        for (int i = 0; i < tabla->filas; i++) {            
            float val = strtof(tabla->regs[i].variacion, NULL);
            if(val < 0) {
                sprintf(fila, DATOS_TD_HTML,
                    tabla->regs[i].especie, tabla->regs[i].vencimiento, tabla->regs[i].cantNominalCompra, tabla->regs[i].precioCompra, tabla->regs[i].precioVenta, tabla->regs[i].cantNominalVenta, tabla->regs[i].ultimo, tabla->regs[i].variacion,
                    tabla->regs[i].apertura, tabla->regs[i].min, tabla->regs[i].max, tabla->regs[i].cierreAnterior, tabla->regs[i].volumen, tabla->regs[i].monto, tabla->regs[i].operacion, tabla->regs[i].hora
                );
                float compra = strtof(tabla->regs[i].precioCompra, NULL);
                float venta = strtof(tabla->regs[i].precioVenta, NULL);
                float apertura = strtof(tabla->regs[i].apertura, NULL);
                if ( compra < apertura && venta < apertura) {
                    strcat(filas, INICIO_TR_HTML_COLOR);
                } else {
                    strcat(filas, INICIO_TR_HTML);
                }
                strcat(filas, fila);
                strcat(filas, FIN_TR_HTML);
            }
        }
        fprintf(html, buf, filas);
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
    t_tabla *tabla = crearTabla();
    char *aux = pagina;
    char *td = "<td";
    char *registro;
    
    char dato[16];
    int iDato = 0;
    int i, j;

    while ((registro = strstr(aux, td)) != NULL) {
        agregarRegistro(tabla);
        iDato = 0;
        while ((registro = strstr(aux, td)) != NULL && iDato < MAX_DATOS) {
            if(iDato != 7) {
                while (*registro++ != INICIO_TAG);
                for(i = 0, j = 0; registro[i] != FIN_TAG; i++) {
                    if(registro[i] == '.') {
                        continue;
                    }
                    if(registro[i] == ',') {
                        registro[i] = '.';
                    }
                    dato[j] = registro[i];
                    j++;
                }
            }
            else {
                while (*registro++ != INICIO_TAG);
                while (*registro++ != INICIO_TAG);
                for(i = 0, j = 0; registro[i] != '%'; i++) {
                    if(registro[i] == '.') {
                        continue;
                    }
                    if(registro[i] == ',') {
                        registro[i] = '.';
                    }
                    dato[j] = registro[i];
                    j++;
                }
            }
            dato[j] = '\0';
            guardarDatoEnRegistro(&(tabla->regs[(tabla->filas)-1]), iDato, dato);
            aux = registro;
            iDato++;
        }
    }

    return tabla;
}
