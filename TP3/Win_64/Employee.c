#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Employee* employee_new()
{
    return (Employee*)malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* SueldoStr)
{

    Employee* pEmployee;
    pEmployee = employee_new();

    if(pEmployee != NULL  && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && SueldoStr!=NULL)
    {
        employee_setId(pEmployee,atoi(idStr));
		employee_setNombre(pEmployee,nombreStr);
		employee_setHorasTrabajadas(pEmployee,atoi(horasTrabajadasStr));
		employee_setSueldo(pEmployee,atoi(SueldoStr));
    }


    return pEmployee;
}

//-------------------------------------------------------
int employee_setId(Employee* this,int id)
{
int todoOk = 0;
    if(this!=NULL && id >=0)
    {
        this->id=id;
        todoOk = 1;
    }
return todoOk;
}

int employee_getId(Employee* this,int* id)
{
int todoOk = 0;
    if(this != NULL && id != NULL)
    {
       *id = this->id;
       todoOk = 1;
    }
return todoOk;
}

//-------------------------------------------------------

int employee_setNombre(Employee* this,char* nombre)
{
int todoOk = 0;
    if(this!=NULL && nombre != NULL && strlen(nombre) >= 2 && strlen(nombre)< 20)
    {
        strcpy(this->nombre,nombre);
        todoOk = 1;
    }
return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
int todoOk = 0;
    if(this!=NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        todoOk = 1;
    }
return todoOk;
}

//-------------------------------------------------------

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
int todoOk = 0;
    if(this!=NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas=horasTrabajadas;
        todoOk = 1;
    }
return todoOk;

}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
int todoOk = 0;
    if(this!=NULL&& horasTrabajadas != NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        todoOk = 1;
    }
return todoOk;

}

//-------------------------------------------------------

int employee_setSueldo(Employee* this,int sueldo)
{
int todoOk = 0;
    if(this!=NULL && sueldo > 0)
    {
     this->sueldo=sueldo;
     todoOk = 1;
    }
return todoOk;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
int todoOk = 0;
    if(this!=NULL&& sueldo != NULL)
    {
        *sueldo=this->sueldo;
        todoOk = 1;
    }
return todoOk;
}

//-------------------------------------------------------

void employee_delete(Employee*this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

int employee_ComparaId(void* a, void* b)
{
    int retorno=0;
    Employee* Aux1;
    Employee* Aux2;
    if(a != NULL && b != NULL)
    {
        Aux1 = (Employee*)a;
        Aux2= (Employee*)b;
        if(Aux1->id > Aux2->id)
        {
            retorno = 1;
        }
        else if(Aux1->id < Aux2->id)
        {
            retorno =-1;
        }
    }

    return retorno;
}

int employee_ComparaSueldo(void* a, void* b)
{
    int retorno=0;
    Employee* Aux1;
    Employee* Aux2;
    if(a != NULL && b != NULL)
    {
        Aux1 = (Employee*)a;
        Aux2= (Employee*)b;
        if(Aux1->sueldo > Aux2->sueldo)
        {
            retorno = 1;
        }
        else if(Aux1->sueldo < Aux2->sueldo)
        {
            retorno =-1;
        }
    }

    return retorno;
}

int employee_ComparaHorasTrabajadas(void* a, void* b)
{
    int retorno=0;
    Employee* Aux1;
    Employee* Aux2;
    if(a != NULL && b != NULL)
    {
        Aux1 = (Employee*)a;
        Aux2= (Employee*)b;
        if(Aux1->horasTrabajadas > Aux2->horasTrabajadas)
        {
            retorno = 1;
        }
        else if(Aux1->horasTrabajadas < Aux2->horasTrabajadas)
        {
            retorno =-1;
        }
    }

    return retorno;
}

int employee_ComparaNombre(void* a, void* b)
{
    int retorno=0;
    Employee* p1;
    Employee* p2;

    if(a != NULL && b != NULL)
    {
        p1 = (Employee*)a;
        p2 = (Employee*)b;
        retorno =strcmp(p1->nombre,p2->nombre);
    }

return retorno;
}
