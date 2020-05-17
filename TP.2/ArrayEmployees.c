#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validation.h"


int SearchEmployee(int id, eEmployee* list, int tam)
{
    int retorno = -1;

    for(int i=0; i<tam; i++)
    {
        if(list[i].id==id && list[i].isEmpty == 0)
        {
            retorno = i;
            break;

        }
    }
    return retorno;
}



//FUNCIONES PARA INICIALIZAR
int isEmpty(eEmployee* list, int len)
{


    int indice = -1;

    for(int i =0; i< len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int initEmployees(eEmployee* list, int len)//Inicia los datos en 0
{

    for(int i=0; i<len; i++)
    {
        list[i].isEmpty=1;
        strcpy(list[i].name," ");
        strcpy(list[i].lastName," ");
        list[i].salary=0;
        list[i].sector=0;
        list[i].id=0;
    }
    return 0;
}


//FUNCIONES PARA AÑADIR
int addEmployees(int idx,eEmployee* list,int len)
{
    int TODOok = 0;
    int retorno = isEmpty(list, len);
    eEmployee auxEmployee;

    printf("***** Alta Empleado *****\n\n");

    if(retorno == -1)
    {
        printf("Sistema Completo...\n\n");
    }
    else
    {
        auxEmployee.id = idx;
        getStr("\nIngrese el nombre del empleado: ", auxEmployee.name);
        getStr("\nIngrese el apellido del empleado: ", auxEmployee.lastName);
        auxEmployee.salary = getFloat("\nIngrese el salario: ");
        auxEmployee.sector = getInt("\nIngrese el sector: ");
        auxEmployee.isEmpty = 0;

        list[retorno] = auxEmployee;
        TODOok = 1;

    }
    return TODOok;
}



//BUSCA EMPLEADO POR ID PARA MODIFICAR LOS DATOS

int findEmployeeById(eEmployee* list, int len, int id)
{

    int existe;
    char confirma;
    int opcion;
    char newName[51];
    char newLastname[51];
    float newSalary;
    int newSector;


    printf("***** Modificar Empleado *****\n");
    id = getInt("\nIntroduzca el id:\n");

    existe = SearchEmployee(id, list, len);

    if(existe == -1)
    {
        printf("Error. No hay registro de un empleado con el id: %d\n", id);

    }

    else
    {
        PrintEmployee(list[existe]);
        printf("Esta seguro de modificar? (s para si/ n para no)\n");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma == 's')
        {
            do
            {
                printf("    1. Modificar nombre\n");
                printf("    2. Modificar apellido\n");
                printf("    3. Modificar salario\n");
                printf("    4. Modificar sector\n\n");
                printf("    5. Salir \n");
                printf("\nElija una opcion\n");
                scanf("%d", &opcion);

                switch(opcion)
                {
                case 1:
                    getStr("\nIngrese el nuevo nombre del empleado: ", newName);
                    strcpy(list[existe].name, newName);
                    printf("Se ha actualizado el nombre con exito\n\n");
                    break;
                case 2:
                    getStr("\nIngrese el nuevo apellido del empleado: ", newLastname);
                    strcpy(list[existe].lastName, newLastname);
                    printf("Se ha actualizado el apellido con exito\n\n");
                    break;
                case 3:
                    newSalary=getFloat("\nIngrese el nuevo salario: ");
                    list[existe].salary = newSalary;
                    printf("Se ha actualizado el sueldo con exito\n\n");
                    break;
                case 4:
                    newSector=getInt("\nIngrese el nuevo Sector: ");
                    list[existe].sector = newSector;
                    printf("Se ha actualizado el sector con exito\n\n");
                    break;
                case 5://Salir
                    opcion=5;
                    printf("Saliendo... \n");
                    break;
                default:
                    printf("No es una opcion valida.\n\n");
                }

            }
            while(opcion != 5);
        }

    }

    return 0;
}


//BAJA
int removeEmployee(eEmployee* list, int len,int id)
{

    int existe;
    char confirma;

    printf("***** Baja Empleado *****\n\n");
    id = getInt("\nIntroduzca el id:\n");

    existe = SearchEmployee(id, list, len);

    if(existe == -1)
    {
        printf("Error. No hay registro de un empleado con el id: %d\n", id);

    }
    else
    {

        PrintEmployee(list[existe]);
        printf("Esta seguro de eliminarlo? (s para si/ n para no)\n");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma == 's')
        {
            list[existe].isEmpty = 1;
            printf("Se ha realizado la baja con exito\n\n");
        }

        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }
    }

    return 0;

}

//FUNCIONES PARA MOSTRAR
void PrintEmployee(eEmployee x)
{
    printf("%d       %10s       %10s           %.2f     %5d\n", x.id, x.name, x.lastName, x.salary, x.sector);


}

int PrintEmployeers(eEmployee* list, int len)
{
    printf("***** Listado de Empleados *****\n");
    printf(" ID           Nombre          Apellido          Salario          Sector\n\n");
    for(int i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            PrintEmployee(list[i]);
        }
    }


    return 0;
}

//FUNCION PARA ORDENAR

int sortEmployees(eEmployee* list, int len)
{

    // int order = 0;

    eEmployee auxEmployee;



    for(int i = 0; i<len; i++)
    {
        for(int j = i+1; j< len ; j++)
        {



            if(strcmp(list[i].lastName, list[j].lastName) > 0)//primer criterio
            {
                auxEmployee = list[i];
                list[i] = list[j];
                list[j] = auxEmployee;


            }
            else if(strcmp(list[i].lastName, list[j].lastName) > 0 && list[i].sector == list[j].sector)//segundo criterio
            {
                auxEmployee = list[i];
                list[i] = list[j];
                list[j] = auxEmployee;

            }
        }
    }
    return 0;
}

//FUNCION SE CALCULA PROMEDIO
int PrintAverage(eEmployee* list, int len)
{
    int i;
    float total = 0;
    int accountant = 0;
    float average = 0;
    int retorno=-1;
    int accountantHigh = 0;

    if(list!=NULL && len>=0)
    {


        for (i=0; i<len; i++)
        {

            if (list[i].isEmpty == 1)
            {
                continue;

            }
            else
            {
                total += list[i].salary;
                accountant++;
            }
        }
        average =  total/ accountant;

        for(i=0; i<len; i++)
        {
            if(list[i].salary>average)
            {
                accountantHigh++;
            }
        }

        printf("\nEl total de los salarios es : %.2f\n",total);
        printf("\nEl promedio total de salarios es : %.2f\n",average);
        printf("\nEl total de empleados que superan los salarios promedio son : %d\n",accountantHigh);
        retorno=0;

    }
    return retorno;


}




