/*
 ============================================================================
 Name        : funciones.c
 Author      : Federico Gomez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "utn.h"

int main(void)
{
	int n;
	utn_getNumero(&n,"Ingrese el numero:","\nError. ",1,9,3);
	printf("El numero ingresado: %d",n);
	return 0;
}
