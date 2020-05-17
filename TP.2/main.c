#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

//#define A 1000
#define A 3
#define CANTINGRESADOS 0

/*1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún empleado.*/

int main()
{
    int opcion;
    int flag = 0;
    int proximoId = 1000;
    eEmployee list[A];
    initEmployees(list, A);
    proximoId += CANTINGRESADOS;


        do
        {
            printf("\n------Menu de empleados------\n");
            printf("\n1. Alta \n");
            printf("2. Modificar \n");
            printf("3. Baja de empleado \n");
            printf("4. Mostrar listado(ordenados alfabeticamente por Apellido y Sector) \n");
            printf("5. Mostrar total de salarios y promedio, y cuantos empleados superan el salario promedio \n");
            printf("6. Salir \n");
            printf("\nElija una opcion\n");
            scanf("%d", &opcion);



            switch(opcion)
            {
            case 1:// se pide que ingrese los datos del empleado, se muestra la lista de empleados para ver cada vez que se carga un empleado mas

                system("cls");


                if(addEmployees(proximoId,list, A))
                {
                    proximoId++;
                }
                flag = 1;


                break;

            case 2:// se muestra la lista de los empleados con sus datos, despues se pide la id del empleado para modificar dichos datos.
                if(flag == 1)
                {
                    system("cls");
                    PrintEmployeers(list, A);
                    printf("\n");
                    findEmployeeById(list, A, 0);
                }
                else
                {
                    printf("\nNo hay empleados cargados\n");


                }
                break;

            case 3://se ingresa la ID del empleado para darle de baja, se valida preguntando si le quiere dar de baja si o no
                if(flag == 1)
                {
                    system("cls");
                    PrintEmployeers(list, A);
                    printf("\n");
                    removeEmployee(list, A,0);
                }
                else
                {
                  printf("\nNo hay empleados cargados\n");


                }
                break;

            case 4://se muestra la lista de empleados ya ordenada
                if(flag == 1)
                {

                    PrintEmployeers(list, A);
                    printf("\n");
                    sortEmployees(list, A);
                    PrintEmployeers(list, A);


                }
                else
                {
                    printf("\nNo hay empleados cargados\n");


                }
                break;
            case 5:// se muestra la lista. Se hace la suma de los salarios y se calcula el promedio
                    PrintEmployeers(list, A);
                    PrintAverage(list, A);
                    flag = 1;
                    break;

            case 6://Salir
                opcion=6;
                printf("Saliendo... \n");
                break;

            default:
                printf("Error. Por favor elija una opcion valida.\n");
                break;

            }
            system("pause");//pone pausa
            system("cls");//limpia la consola


        }
        while(opcion != 6);




    return 0;


}
