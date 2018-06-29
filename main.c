#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "ArrayList.h"
#include "Parser.h"
#include "Archivo.h"

/**
    Realizar un programa que lee de un archivo los datos de empleados y los guarda en un arraylist de entidades
    empleado.
    Luego, debera filtrar los empleados leidos, segun la horas que trabajaron, y generar una lista nueva en donde solo se encuentren
    los que trabajaron mas de 120 horas.

    Para hacer esta operacion, se debera desarrollar la funcion "filter" en la biblioteca ArrayList, La cual recibe la lista y una funcion.
    La funcion filter ejecutara la funcion recibida como parametro por cada item de la lista, y le pasara en cada llamada, uno de los items.
    De esta manera la funcion pasada como parametro podra analizar el item recibido y devolver un "1" en el caso de que el item deba permanacer
    en la lista generada y un "0" si se debe sacar de la lista. La funcion filter debera devolver un nuevo arraylist con los items que la funcion
    pasada como argumento determino que se incluyan.

    Una vez generada la nueva lista filtrada, se debera generar un archivo de salida "jornada_completa.csv" con las mismas columnas que el original.
*/

int main()
{
    // Definir lista de empleados
    ArrayList* listaEmpleados;
    ArrayList* listaEmpleados120hs;

    // Crear lista empledos
    //...
    listaEmpleados = al_newArrayList();
    listaEmpleados120hs = al_newArrayList();

    // Leer empleados de archivo data.csv
    if(parser_parseEmpleados("data.csv",listaEmpleados)==1)
    {
        // Filtrar empleados
        printf("Filtrando empleados\n");
        //al_map(listaEmpleados,em_calcularSueldo);
        listaEmpleados120hs = al_filter(listaEmpleados,em_trabajaMasDe120Horas);

        // Generar archivo de salida
        if(generarArchivoFiltrado("jornada_completa.csv",listaEmpleados120hs)==1)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");
    }
    else
        printf("Error leyendo empleados\n");


    return 0;
}
