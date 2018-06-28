#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "utn.h"



Empleado* Empleado_newParametros(char* strId,char* nombre, char* strHorasTrabajadas)
{
    int id;
    int horasTrabajadas;
    Empleado* this;
    if(esNumerico(strId))
    {
        id = atoi(strId);
        if(esNumerico(strHorasTrabajadas))
        {
            horasTrabajadas = atoi(strHorasTrabajadas);
            if(esSoloLetras(nombre))
            {
                this = Empleado_new();
                if( !Empleado_setId(this,id) &&
                    !Empleado_setNombre(this,nombre) &&
                    !Empleado_setHorasTrabajadas(this,horasTrabajadas)
                    )
                {
                    return this;
                }
            }
        }
    }
    Empleado_delete(this);
    return NULL;
}



Empleado* Empleado_new()
{
    Empleado* this;
    this=malloc(sizeof(Empleado));
    return this;
}

void Empleado_delete(Empleado* this)
{
    free(this);
}

int Empleado_setId(Empleado* this,int id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int Empleado_getId(Empleado* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Empleado_setNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_getNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int em_trabajaMasDe120Horas(void* item)
{

    int horasTrabajadas,retorno=0;
    if(item!=NULL)
    {
        Empleado_getHorasTrabajadas(item,&horasTrabajadas);
        if(horasTrabajadas>=120)
        {
            retorno = 1;
        }
    }
    return retorno;
}
