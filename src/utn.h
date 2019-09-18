/*
 * utn.h
 *
 *  Created on: 14 sep. 2019
 *      Author: federico
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#ifndef UTN_H_
#define UTN_H_

static int getInt(int* pResultado);

int utn_getNumero(int* pResultado,
		char* mensaje,
		char* mensajeError,
		int minimo,
		int maximo,
		int reintentos);




#endif /* UTN_H_ */
