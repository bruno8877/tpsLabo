#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int cont=0;
    char auxId[50];
    char auxNombre[50];
    char auxHorasTrabajadas[50];
    char auxSueldo[50];
    Employee* auxEmployee;
    auxEmployee = employee_new();
    int r;

    if(pFile == NULL)
    {
        return -1;
    }

    while(!feof(pFile))
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
        if(r == 4)
        {
            auxEmployee = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
            ll_add(pArrayListEmployee, auxEmployee);
            cont++;
        }

    }
    return 0;
}



/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee auxEmployee;
    int i=0;
    fread(&auxEmployee, sizeof(Employee), 1, pFile);

    while(!feof(pFile))
    {
        Employee* employeeNew;
        employeeNew = employee_new();
        employee_setId(employeeNew,auxEmployee.id);
        employee_setHorasTrabajadas(employeeNew,auxEmployee.horasTrabajadas);
        employee_setNombre(employeeNew,auxEmployee.nombre);
        employee_setSueldo(employeeNew,auxEmployee.sueldo);
        i++;
        ll_add(pArrayListEmployee,employeeNew);
        fread(&auxEmployee,sizeof(Employee),1,pFile);
    }
    return 1;
}
