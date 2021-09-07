#ifndef __MACROS_H
#define __MACROS_H

#define HEADER_CONSOLA          "Especie-Vencimiento-Cant. Nominal-Compra-Venta-Cant. Nominal-Ultimo-Variacion-Apertura-Min-Max-Cierre Anterior-Volumen-Monto-Operacion-Hora\n"
#define FORMATO_FILA_CONSOLA    "%s - %s - %s - %s - %s - %s - %s - %s - %s - %s - %s - %s - %s - %s - %s - %s\n"

#define HEADER_CSV              "Especie; Precio de compra; Precio de venta; Apertura; Precio Minimo; Precio Maximo;\n"
#define FORMATO_FILA_CSV        "%s; %s; %s; %s; %s; %s;\n"

#define INICIO_TR_HTML          "<tr style=\"font-size:12px; text-align:center;\">\n"
#define INICIO_TR_HTML_COLOR    "<tr style=\"font-size:12px; text-align:center; background-color: green\">\n"
#define DATOS_TD_HTML           "<td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td>\n"
#define FIN_TR_HTML             "</tr>\n"

#define INICIO_TD               "<td"
#define INICIO_TAG              '>'
#define FIN_TAG                 '<'

#endif // __MACROS_