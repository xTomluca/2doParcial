#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Empleado.h"

/** \brief  Parser
 * \param   char* fileName is path file
 * \param   ArrayList* listaEmpleados
 * \return  Return [1]
 */
int parser_parseEmpleados(char* fileName, ArrayList* listaEmpleados)
{
    Empleado* aux;
    char id[50];
    char nombre[50];
    char horasTrabajadas[50];
    FILE* fp;
    fp = fopen("data.csv","r");
    fscanf(fp,"%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas);
    do{
        fscanf(fp,"%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas);
        aux = Empleado_newParametros(id,nombre,horasTrabajadas);
        if(aux!=NULL)
            al_add(listaEmpleados,aux);
    }while(!feof(fp));

    return 1; // OK
}
