#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "validaciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE*pFile;

    pFile = fopen(path, "r");

    if(pFile!=NULL)
    {
        parser_EmployeeFromText(pFile,pArrayListEmployee);
        printf("\nLos datos del archivo de modo texto se han cargado con exito...\n");
    }
    else
    {
        printf("No se pudo cargar el archivo");
    }
    fclose(pFile);
    return 0;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{

    FILE *pFile= fopen(path, "rb");

    if(pFile!= NULL)
    {
        parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        printf("\nLos datos del archivo de modo binario se han cargado con exito...\n");

    }
    else
    {
        printf("\nEl archivo no se pudo cargar.\n");
        fclose(pFile);
    }
    return 0;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    char auxId[50];
    char auxNombre[50];
    char auxHorasTrabajadas[50];
    char auxSalario[50];
    int tamList;
    int auxID;
    int auxHsTrabajadas;
    int auxSueldo;
    int i;
    int retorno=0;
    Employee* auxNewEmployee;

    tamList = ll_len(pArrayListEmployee);
    auxNewEmployee = employee_new();
    if(pArrayListEmployee !=NULL)
    {
        auxID=getInt("Ingrese el id del nuevo empleado:\n");
        itoa(auxID, auxId, 10);
        for(i =0; i<tamList; i++)
        {
            auxNewEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            if( auxNewEmployee->id == auxID)
            {
                printf("El id que intenta agregar ya esta en uso...\n");
                break;
            }
        }
        if(auxNewEmployee->id!=auxID)
        {
            getStr("ingrese el nombre: \n", auxNombre);

            auxHsTrabajadas = getInt("ingrese las cantidad de horas trabajadas: \n");
            itoa(auxHsTrabajadas,auxHorasTrabajadas,10);

            auxSueldo=getInt("ingrese el salario: \n");
            itoa(auxSueldo,auxSalario,10);

            auxNewEmployee = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSalario);
            if(ll_add(pArrayListEmployee, auxNewEmployee)==0)
            {
                printf("\nEmpleado cargado\n");
                retorno = 1;
            }
            else
            {
                employee_delete(auxNewEmployee);
                printf("\nError al agregar empleado\n");
            }

        }
    }

    return retorno;

}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    char auxNombre[128];
    int auxId;
    int auxHorasTrabajadas;
    int auxSueldo;
    int tamList;
    int option;


    Employee* auxEmployeeModify;
    tamList = ll_len(pArrayListEmployee);

    if(pArrayListEmployee!=NULL)
    {
        auxId = getInt("\nIngrese el id del empleado a modificar: \n");

        for(int i=0; i<tamList; i++)
        {
            auxEmployeeModify = (Employee*)ll_get(pArrayListEmployee, i);
            if(auxId==auxEmployeeModify->id)
            {
                system("cls");
                do
                {
                    //printf("\n1.Para ingresar el nombre del empleado\n2.Para ingresar las horas trabajadas\n3.Para ingresar el sueldo\n4 Para salir.");
                    printf("\n------Menu de modificacion de empleado------\n");
                    printf("\n-.Que desea modificar.- \n");
                    printf("\n1. Para modificar el nombre del empleado.\n");
                    printf("2. Para modificar las horas trabajadas\n");
                    printf("3. Para modificar el sueldo \n");
                    printf("4. Para salir. \n");
                    option=getInt("Ingrese la opcion: ");

                    switch(option)
                    {
                    case 1:
                        system("cls");
                        getStr("Ingrese el nuevo nombre \n", auxNombre);
                        employee_setNombre(auxEmployeeModify, auxNombre);

                        break;
                    case 2:
                        system("cls");
                        auxHorasTrabajadas = getInt("ingrese la cantidad horas trabajadas\n");
                        employee_setHorasTrabajadas(auxEmployeeModify, auxHorasTrabajadas);
                        break;
                    case 3:
                        system("cls");
                        auxSueldo = getInt("ingrese el salario \n");
                        employee_setSueldo(auxEmployeeModify, auxSueldo);
                        break;
                    case 4:
                        system("cls");
                        option = 4;
                        break;
                    default:
                        printf("\nIngrese una opcion valida...\n");
                        break;
                    }
                }
                while(option != 4);

            }

        }

    }

    return 0;


}

/** \brief Ordena por nombre, horas, sueldo y id los datos de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

    int option;
    LinkedList* auxList=ll_clone(pArrayListEmployee);
    if(pArrayListEmployee != NULL)
    {
        do
        {
            printf("\n------Menu de ordenamiento de empleados------\n");
            printf("\n-.De que manera desea ordenar los empleados.- \n");
            printf("\n1. Por nombre.\n");
            printf("2. Por ID.\n");
            printf("3. Por sueldo.\n");
            printf("4. Por horas trabajadas.\n");
            printf("5. Para salir.\n");
            option=getInt("Ingrese la opcion: ");

            switch(option)
            {
            case 1:
                system("cls");
                system("pause");
                ll_sort(auxList, employee_ComparaNombre,1);
                controller_ListEmployee(auxList);

                break;

            case 2:
                system("cls");
                system("pause");
                ll_sort(auxList, employee_ComparaId,1);
                controller_ListEmployee(auxList);

                break;

            case 3:
                system("cls");
                system("pause");
                ll_sort(auxList, employee_ComparaSueldo,1);
                controller_ListEmployee(auxList);

                break;

            case 4:
                system("cls");
                system("pause");
                ll_sort(auxList, employee_ComparaHorasTrabajadas,1);
                controller_ListEmployee(auxList);

                break;

            case 5:
                system("cls");
                option = 5;
                break;

            default:
                printf("\nIngrese una opcion valida...\n");
                break;
            }
        }while(option != 5);

    }

    return 0;
}


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int auxId;
    int tamList;
    tamList = ll_len(pArrayListEmployee);


    if(pArrayListEmployee !=NULL)
    {
        auxId = getInt("ingrese id del empleado a eliminar: \n");

        for(int i=0; i<tamList; i++)
        {
            auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);

            if(auxEmployee->id == auxId)
            {
                ll_remove(pArrayListEmployee, i);
                printf("\nEl empleado se ha dado de baja...\n");
                employee_delete(auxEmployee);

                break;
            }
        }
    }
    return 0;
}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int auxId;
    char auxNombre[50];
    int auxHorasTrabajadas;
    int auxSalario;
    int tam;

    tam = ll_len(pArrayListEmployee);

    if(pArrayListEmployee!=NULL)
    {
        printf("   Id           Nombre       Horas trabajadas     Sueldo \n");

        for(int i=1; i<tam; i++)
        {
            auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);

            employee_getId(auxEmployee, &auxId);
            employee_getNombre(auxEmployee,auxNombre);
            employee_getHorasTrabajadas(auxEmployee,&auxHorasTrabajadas);
            employee_getSueldo(auxEmployee,&auxSalario);
            printf("%5d  %15s %15d  %15d\n",auxId, auxNombre, auxHorasTrabajadas, auxSalario);

        }
    }
    else
    {
        printf("\nError, los datos no se pudieron cargar");
    }
    return 0;
}



/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int tamList;

    Employee* auxEmployeeSaveText;
    FILE* pFile;
    pFile = fopen(path, "w");

    tamList = ll_len(pArrayListEmployee);

    if(pFile != NULL)
    {

        fprintf(pFile, "ID,NOMBRE,HORAS TRABAJADAS,SUELDO\n");

        if(pArrayListEmployee!=NULL)
        {
            for(int i=1; i<tamList; i++)
            {
                auxEmployeeSaveText = (Employee*)ll_get(pArrayListEmployee, i);
                fprintf(pFile, "%d,%s,%d,%d\n", auxEmployeeSaveText->id
                        , auxEmployeeSaveText->nombre
                        , auxEmployeeSaveText->horasTrabajadas
                        , auxEmployeeSaveText->sueldo);
            }
            printf("\nArchivo guardado...");
        }
        fclose(pFile);
        return 1;
    }
    else
    {
        printf("Error, nose pudo guardar..\n");
        return 0;
    }

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int tamList;

    Employee* auxEmployeeSaveBin;
    FILE*pFile;
    pFile= fopen(path, "wb");

    tamList = ll_len(pArrayListEmployee);

    if(pFile == NULL)
    {

        printf("Error al guardar..\n");
        return 0;
    }

    if(pArrayListEmployee!=NULL)
    {
        for(int i=1; i<tamList; i++)
        {
            auxEmployeeSaveBin = (Employee*)ll_get(pArrayListEmployee, i);
            fwrite(auxEmployeeSaveBin,sizeof(Employee), 1, pFile);
        }
        printf("\nArchivo Guardado...\n");
    }

    fclose(pFile);
    return 1;

}

