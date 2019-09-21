#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int isValidUnsignedInt(char* cadena)
{
	int retorno = -1; //valor que indica que la funci�n no ha cumplido su cometido
	int i = 0; //variable para ir recorriendo el array 'cadena'
	if(cadena != NULL) //elimina el caso en el que el usuario presione ENTER sin haber escrito nada
	{
		while(cadena[i] != '\0') //mientras que no haya llegado al final de la cadena, entra en el loop
		{
			if(cadena[i] < '0' || cadena[i] > '9') //validaci�n: entra al if si el caracter evaluado NO es un numero del 0 al 9
			{
				break; //no hay necesidad de seguir recorriendo la cadena pq ya encontr� un caracter que NO es num�rico, ya la validaci�n fall�, es decir, la cadeno NO es num�rica
			}
			i++; //si llega ac� es porque el caracter si es num�rico, entonces toca avanzar al pr�ximo caracter de la cadena
		}
		if(cadena[i] == '\0') //este if es para evaluar si la funci�n sali� del while por haber llegado al final de la cadena, y no por que haya encontrado un caracter no num�rico
		{
			retorno = 1; //valor que indica que la funci�n SI cumpli� su cometido
		}
	}
	
	return retorno;
}

static int getUnsignedInt(int* pResultado)
{
	int retorno = -1; //valor indicativo de que la funci�n NO cumpli� su cometido
	char buffer[64]; //ac� voy a almacenar temporalmente lo que el usuario ingresa para luego validarlo
	fgets(buffer, sizeof(buffer), stdin); //guarda lo que el usuario tipea en la variable 'buffer'
	buffer[strlen(buffer) - 1] = '\0'; //trunca el ingreso del usuario al tama�o de la variable 'buffer' y le pone al final el indicador de final de cadena.
	
	if(isValidUnsignedInt(buffer)) //validacion de 'buffer' utilizando la funci�n apropiada (en este caso, 'esEntero')
	{
		*pResultado = atoi(buffer); //guarda el valor de 'buffer' en la variable cuya direccion es pResultado
		retorno = 1; //valor que indica que la funci�n cumpli� su cometido
	}
	
	return retorno;
}

int utn_getUnsignedInt(int* pResultado,
 char* mensaje,
 char* mensajeError,
 int minimo,
 int maximo,
 int reintentos)
{
	int retorno;
	int numero;
	
	do //que al menos una vez muestre el mensaje pidiendo el ingreso del valor
	{
		printf(mensaje);
		if(getUnsignedInt(&numero) == 1) //la funcion getInt (valida que el ingreso sea un entero y lo guarda en pResultado). Si es asi, retorna 1... y entra al if
		{
			if(numero <= maximo && numero >= minimo) //si numero esta dentro del rango, sale del loop 
			{
				break;		
			}
		}
		reintentos--; //sino, resta un reintento.
		printf(mensajeError); //y muestra mensaje de error
	} while(reintentos > 0); // hasta que reintentos llegue a 0
	
	if(reintentos == 0) //sino, si es 0, es decir que no quedan reintentos...
	{
		retorno = -1; // este valor indica que la funci�n utn_getEntero no logr� guardar un numero, pq se acabaron los intentos
	}
	else
	{
		retorno = 0; // este valor indica que la funcion logro guardar un numero entero que est� dentro del rango permitido
		*pResultado = numero; // asigno a *pResultado el valor guardado en la variable numero
	}
	
	return retorno; //la funcion utn_getEntero tiene que devolver un valor, el guardado en retorno
}


static int isValidSignedInt(char* cadena)
{
	int retorno = -1; //valor que indica que la funci�n no ha cumplido su cometido
	int i = 0; //variable para ir recorriendo el array 'cadena'
	if(cadena != NULL) //elimina el caso en el que el usuario presione ENTER sin haber escrito nada
	{
		while(cadena[i] != '\0') //mientras que no haya llegado al final de la cadena, entra en el loop
		{
			if(i == 0)
			{
				if((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != '-' && cadena[i] != '+')) //validaci�n: entra al if si el caracter evaluado NO es un numero del 0 al 9 ni '+' ni '-'
				{
					break; //no hay necesidad de seguir recorriendo la cadena pq ya encontr� un caracter que NO es v�lido, ya la validaci�n fall�
				}
			}
			else
			{
				if(cadena[i] < '0' || cadena[i] > '9') //validaci�n: entra al if si el caracter evaluado NO es un numero del 0 al 9
				{
					break; //no hay necesidad de seguir recorriendo la cadena pq ya encontr� un caracter que NO es num�rico, ya la validaci�n fall�, es decir, la cadeno NO es num�rica
				}
			}
			i++; //si llega ac� es porque el caracter si es num�rico, entonces toca avanzar al pr�ximo caracter de la cadena			
		}
		if(cadena[i] == '\0') //este if es para evaluar si la funci�n sali� del while por haber llegado al final de la cadena, y no por que haya encontrado un caracter no valido
		{
			retorno = 1; //valor que indica que la funci�n SI cumpli� su cometido
		}
	}
	
	return retorno;
}

static int getSignedInt(int* pResultado)
{
	int retorno = -1; //valor indicativo de que la funci�n NO cumpli� su cometido
	char buffer[64]; //ac� voy a almacenar temporalmente lo que el usuario ingresa para luego validarlo
	fgets(buffer, sizeof(buffer), stdin); //guarda lo que el usuario tipea en la variable 'buffer'
	buffer[strlen(buffer) - 1] = '\0'; //trunca el ingreso del usuario al tama�o de la variable 'buffer' y le pone al final el indicador de final de cadena.
	
	if(isValidSignedInt(buffer)) //validacion de 'buffer' utilizando la funci�n apropiada (en este caso, 'esEntero')
	{
		*pResultado = atoi(buffer); //guarda el valor de 'buffer' en la variable cuya direccion es pResultado
		retorno = 1; //valor que indica que la funci�n cumpli� su cometido
	}
	
	return retorno;
}


int utn_getSignedInt(int* pResultado,
 char* mensaje,
 char* mensajeError,
 int minimo,
 int maximo,
 int reintentos)
{
	int retorno;
	int numero;
	
	do //que al menos una vez muestre el mensaje pidiendo el ingreso del valor
	{
		printf(mensaje);
		if(getSignedInt(&numero) == 1) //la funcion getInt (valida que el ingreso sea un entero y lo guarda en pResultado). Si es asi, retorna 1... y entra al if
		{
			if(numero <= maximo && numero >= minimo) //si numero esta dentro del rango, sale del loop 
			{
				break;		
			}
		}
		reintentos--; //sino, resta un reintento.
		printf(mensajeError); //y muestra mensaje de error
	} while(reintentos > 0); // hasta que reintentos llegue a 0
	
	if(reintentos == 0) //sino, si es 0, es decir que no quedan reintentos...
	{
		retorno = -1; // este valor indica que la funci�n utn_getEntero no logr� guardar un numero, pq se acabaron los intentos
	}
	else
	{
		retorno = 0; // este valor indica que la funcion logro guardar un numero entero que est� dentro del rango permitido
		*pResultado = numero; // asigno a *pResultado el valor guardado en la variable numero
	}
	
	return retorno; //la funcion utn_getEntero tiene que devolver un valor, el guardado en retorno
}


static int isValidDouble(char* cadena)
{
	int retorno = -1; //valor que indica que la funci�n no ha cumplido su cometido
	int i = 0; //variable para ir recorriendo el array 'cadena'
	char puntoUsado = 0;
	
	if(cadena != NULL) //elimina el caso en el que el usuario presione ENTER sin haber escrito nada
	{
		while(cadena[i] != '\0') //mientras que no haya llegado al final de la cadena, entra en el loop
		{
			if(i == 0)
			{
				if((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != '-' && cadena[i] != '+')) //validaci�n: entra al if si el caracter evaluado NO es un numero del 0 al 9 ni '+' ni '-'
				{
					break; //no hay necesidad de seguir recorriendo la cadena pq ya encontr� un caracter que NO es v�lido, ya la validaci�n fall�
				}
			}
			else if (i == 1)
			{
				if(cadena[i] < '0' || cadena[i] > '9') //validaci�n: entra al if si el caracter evaluado NO es un numero del 0 al 9
				{
					break; //no hay necesidad de seguir recorriendo la cadena pq ya encontr� un caracter que NO es num�rico, ya la validaci�n fall�, es decir, la cadeno NO es num�rica
				}
			}
			else
			{
				if(puntoUsado == 1)
				{
					if(cadena[i] < '0' || cadena[i] > '9') //validaci�n: entra al if si el caracter evaluado NO es un numero del 0 al 9
					{
						break; //no hay necesidad de seguir recorriendo la cadena pq ya encontr� un caracter que NO es num�rico, ya la validaci�n fall�, es decir, la cadeno NO es num�rica
					}
				}
				else
				{
					if((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != '.' )) //validaci�n: entra al if si el caracter evaluado NO es un numero del 0 al 9 ni '+' ni '-'
					{
						break; //no hay necesidad de seguir recorriendo la cadena pq ya encontr� un caracter que NO es v�lido, ya la validaci�n fall�
					}
					if(cadena[i] == '.')
					{
						puntoUsado = 1;
					}
				}
			}
			i++; //si llega ac� es porque el caracter si es num�rico, entonces toca avanzar al pr�ximo caracter de la cadena			
		}
		if(cadena[i] == '\0') //este if es para evaluar si la funci�n sali� del while por haber llegado al final de la cadena, y no por que haya encontrado un caracter no valido
		{
			retorno = 1; //valor que indica que la funci�n SI cumpli� su cometido
		}
	}
	
	return retorno;
}

static int getDouble(double* pResultado)
{
	int retorno = -1; //valor indicativo de que la funci�n NO cumpli� su cometido
	char buffer[64]; //ac� voy a almacenar temporalmente lo que el usuario ingresa para luego validarlo
	fgets(buffer, sizeof(buffer), stdin); //guarda lo que el usuario tipea en la variable 'buffer'
	buffer[strlen(buffer) - 1] = '\0'; //trunca el ingreso del usuario al tama�o de la variable 'buffer' y le pone al final el indicador de final de cadena.
	
	if(isValidDouble(buffer)) //validacion de 'buffer' utilizando la funci�n apropiada (en este caso, 'esEntero')
	{
		*pResultado = atof(buffer); //guarda el valor de 'buffer' en la variable cuya direccion es pResultado
		retorno = 1; //valor que indica que la funci�n cumpli� su cometido
	}
	
	return retorno;
}


int utn_getDouble(double* pResultado,
 char* mensaje,
 char* mensajeError,
 double minimo,
 double maximo,
 int reintentos)
{
	int retorno;
	double numero;
	
	do //que al menos una vez muestre el mensaje pidiendo el ingreso del valor
	{
		printf(mensaje);
		if(getDouble(&numero) == 1) //la funcion getInt (valida que el ingreso sea un entero y lo guarda en pResultado). Si es asi, retorna 1... y entra al if
		{
			if(numero <= maximo && numero >= minimo) //si numero esta dentro del rango, sale del loop 
			{
				break;		
			}
		}
		reintentos--; //sino, resta un reintento.
		printf(mensajeError); //y muestra mensaje de error
	} while(reintentos > 0); // hasta que reintentos llegue a 0
	
	if(reintentos == 0) //sino, si es 0, es decir que no quedan reintentos...
	{
		retorno = -1; // este valor indica que la funci�n utn_getEntero no logr� guardar un numero, pq se acabaron los intentos
	}
	else
	{
		retorno = 0; // este valor indica que la funcion logro guardar un numero entero que est� dentro del rango permitido
		*pResultado = numero; // asigno a *pResultado el valor guardado en la variable numero
	}
	
	return retorno; //la funcion utn_getEntero tiene que devolver un valor, el guardado en retorno
}
















