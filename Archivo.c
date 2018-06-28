#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "ArrayList.h"
#include "Archivo.h"

int generarArchivoFiltrado(char* fileName,ArrayList* listaEmpleados120hs)
{
    FILE* fp = fopen(fileName,"w");
    Empleado* aux;
    int i,id,horasTrabajadas,retorno=0;
    char nombre[50];
    if(fp!=NULL)
    {
        for(i=0;i<al_len(listaEmpleados120hs);i++)
        {
            aux = al_get(listaEmpleados120hs,i);
            Empleado_getId(aux,&id);
            Empleado_getNombre(aux,nombre);
            Empleado_getHorasTrabajadas(aux,&horasTrabajadas);
            fprintf(fp,"\n%d,%s,%d",id,nombre,horasTrabajadas);
            retorno=1;
        }
        fclose(fp);
    }


    return retorno;
}
