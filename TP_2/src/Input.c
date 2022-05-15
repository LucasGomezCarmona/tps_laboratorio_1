/*
 * Input.c
 *
 *  Created on: 9 may 2022
 *      Author: Lucas
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "Input.h"

#define TRUE 0
#define FALSE 1
#define len 2000

//===========================================================================

char getString(char message, int size)
{
	char string[size];

	if (message != NULL)
	{
		printf("%s", message);
		scanf("%s", string);
	}

	return string;
}

//===========================================================================

int myGets(char* cadena, int longitud)
{
fflush(stdin);
fgets(cadena, longitud, stdin);
cadena[strlen(cadena)-1] = '\0';
return 0;
}

//===========================================================================

int getInt(int* pResultado)
{
int retorno = -1;
char bufferString[4096];

if(myGets(bufferString, sizeof(bufferString)) == 0 && esNumerica(bufferString))
{
	retorno = 0;
	*pResultado = atoi(bufferString);
}
return retorno;
}

//===========================================================================

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
int retorno = -1;
int bufferInt;

if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
{
	do
	{
		printf("%s", mensaje);
			if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		reintentos--;
		printf("%s", mensajeError);
	}while(reintentos >= 0);
}
return retorno;
}

//===========================================================================

/// @brief verifica si la cadena ingresad es númerica
/// @param cadena de caracteres a ser analizada
/// @return retorna 1 (verdadero) si la cadena es numerica, 0 (falso) y -1 en caso de error
int esNumerica(char* cadena)
{
int retorno = 1;
int i=0;

	if(cadena[0] == '-')
	{
		i = 1;
	}

	for( ; cadena[i] != '\0'; i++)
	{
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
		}
	}
return retorno;
}

//===========================================================================

int validarFloat(const char* fm, void* var)
{
    int ch;

    if(!scanf(fm, var))
    {
        while((ch = getchar()) != '\n' && ch != EOF);
        return 1;
    }

    if(getchar() != '\n')
    {
        while((ch = getchar()) != '\n' && ch != EOF);
        return 1;
    }
    return 0;
}

//===========================================================================

int validarAlfanumerico(char variable[]) // valida el si el dato es alfanumerico
{
	int retorno = 1;
	int i;

		for(i=0 ; i<strlen(variable); i++)
		{
			if(!((variable[i]>=65 && variable[i]<=90)||	(variable[i]>=97 && variable[i]<=122)||
				(variable[i]>='0' && variable[i]<='9')))
			{
				printf("\nError ingrese un codigo de vuelo valido");
				retorno = 0;
				break;
			}
		}
	return retorno;
}

//===========================================================================

void PedirAlfanumerico(char nombre[], char mensaje[]) // Piede el dato alfanumerico
{
	int retorno;

		do{
	         printf("\n%s", mensaje);
	         scanf("%s",nombre);
	         retorno = validarAlfanumerico(nombre);

	     }while(retorno == 0);
}

//===========================================================================

void showMenu()
{
	int r;
		int option;
		int otherOption;
		int id;
		int order = 1;
		int firstAddFlag = 0;
		Passenger list[len];
		r = initPassengers(list,len);
		printReturn(r);
		do
		{
			printf("\n1. ALTA\n2. BAJA\n3. MODIFICACION\n4. INFORMAR\n");
			if(utn_getNumero(&option, "\nIngrese una opcion: ","\nERROR numero invalido", 0, 4, 50) == 0)
								{
									printReturn(0);
								}
								else
								{
									printReturn(-1);
								}
			switch(option)
			{
				case 0:
					printf("\nGracias por usar el programa");
					break;

				case 1:
					r = loadPassenger(list, len);
					printReturn(r);
					firstAddFlag = 1;
					break;

				case 2:
					if(firstAddFlag ==0)
					{
						printf("\nERROR. Primero debe ingresar al menos un pasajero.");
						break;
					}
					if(utn_getNumero(&id, "\nIngrese ID: ","\nERROR numero invalido", 1, 2000, 50) == 0)
					{
						printReturn(0);
					}
					else
					{
						printReturn(-1);
					}
					r = removePassenger(list , len, id);
					printReturn(r);
					break;

				case 3:
					if(firstAddFlag ==0)
					{
						printf("\nERROR. Primero debe ingresar al menos un pasajero.");
						break;
					}
					r = modifyPassenger(list, len);
					printReturn(r);
					break;
				case 4:
					if(firstAddFlag ==0)
					{
						printf("\nERROR. Primero debe ingresar al menos un pasajero.");
						break;
					}
					if(utn_getNumero(&otherOption, "\n1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero."
									"			    \n2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el preciopromedio."
									"			    \n3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n0. Salir.\nIngrese opcion: ","\nERROR numero invalido", 0, 3, 50) == 0)
						{
							printReturn(0);
						}
						else
						{
							printReturn(-1);
						}
					switch(otherOption)
					{
						case 1:
							r = sortPassengers(list, len, order);
							printReturn(r);
							break;

						case 2:
							r = totalAndAveragePrice(list, len);
							printReturn(r);
							break;

						case 3:
							r = sortPassengersByCode(list, len, order);
							printReturn(r);
							break;

						case 0:
							printf("\nVolviste al menu principal.");
							break;

					}
					break;

			}
		}while(option != 0);
}

//===========================================================================
