/*
 * utn.c
 *
 *  Created on: 14 sep. 2019
 *      Author: federico
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

static int esNumerica(char* cadena)
{
	int ret = -1;
	int i= 0;
	if(cadena != NULL)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i]<0 || cadena[i]>9)
			{
				break;
			}
			i++;
		}
		if (cadena[i] == '\0')
		{
			ret = 1;
		}
	}
	return ret;
}


static int getInt(int* pResultado)
{
	int ret = -1;
	char buffer[64];
	fgets(buffer,sizeof(buffer),stdin);
	 buffer[strlen(buffer)-1]='\0';



	if(esNumerica(buffer))
	{
		*pResultado = atoi(buffer);
		ret = 1;
	}
	return ret;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno;
	int numero;

	while(reintentos>0) //mientras que los reintentos sean mayores a 0
	{
		printf(mensaje); //muestre en pantalla el mensaje pidiendo un numero
		if(getInt(numero)==1)
		{
			if(numero<=maximo&&numero>=minimo)//si es menor que el maximo y mayor que el minimo, all OK
			{
				break; //all ok, entonces sale
			}
		}
		__fpurge(stdin);

		reintentos--; //resta un reintento
		printf(mensajeError);// da mensaje de error
	}
	if (reintentos==0) //si reintentos quedo en 0, retorno -1, el usuario se paso de la cantidad de reintentos
	{
		retorno=-1; //error en la funcion
	}
	else
	{
		retorno=0; // sino, retorno es 0(no hay error)
		*pResultado = numero; //y guardo el numero en el puntero pResultado
	}

	return retorno; // la funcion devuelve lo guardado en return
}


