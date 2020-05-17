
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validation.h"

//VALIDACION
int getInt(char msj[])
{
    char aux[10];
    int intAdd;

    printf("%s", msj);
    scanf("%s", aux);
    fflush(stdin);
    intAdd = atoi(aux);

    while(intAdd == 0 || intAdd < 0)
    {
        printf("%s", "Error. Por favor Ingrese un solo numero entero \n");
        scanf("%s", aux);
        fflush(stdin);
        intAdd = atoi(aux);
    }

    return intAdd;
}


float getFloat(char msj[])
{
    float aux;
    printf("%s",msj);
    while(scanf("%f", &aux)!=1)
    {
        fflush(stdin);
        printf("Error, Ingrese un valor numerico...\n");
        printf("%s", msj);
    }
    return aux;
}


int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}


void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

int getStr(char msj[], char input[])
{
    char aux[256];
    getString(msj,aux);

    while(esSoloLetras(aux) == 0)
    {
        getString("Error. Por favor Ingrese solo letras \n", aux);
    }
    strcpy(input,aux);
    return 1;
}
