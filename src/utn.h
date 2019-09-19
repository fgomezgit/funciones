/*
 * utn.h
 *
 *  Created on: 14 sep. 2019
 *      Author: federico
 */

#ifndef UTN_H_
#define UTN_H_

int esNumerica(char* cadena);

int getInt(int* pResultado);

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

#endif /* UTN_H_ */
