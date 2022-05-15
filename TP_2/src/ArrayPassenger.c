/*
 * ArrayPassenger.c
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

#define ACTIVE 1
#define PASSIVE 0
#define TRUE 1
#define FALSE 0
#define TURIST 1
#define ECONOMY 2
#define BUSSINES 3

//===========================================================================

int initPassengers(Passenger list[], int len)
{
    if(len>2000)
	{
	    printf("Invalid length");
	    return -1;
	}

	for(int i=0;i<len;i++)
	{
		list[i].isEmpty = TRUE;
	}
	return 0;
}

//===========================================================================

int addPassenger(Passenger list[], int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[])
{

	for(int i=0;i<len;i++)
	{
		if(list[i].isEmpty == TRUE)
		{
			id = i+1;
			list[i].id = id;
			strcpy(list[i].name, name);
			strcpy(list[i].lastname, lastName);
			list[i].price = price;
			list[i].typePassenger = typePassenger;
			strcpy(list[i].flycode, flycode);
			list[i].isEmpty = FALSE;
			return 0;
		}
	}

	return -1;
}

//===========================================================================

int loadPassenger(Passenger list[], int len)
{
	int r;
	int counter = 0;
	int id;
	char name[51];
	char lastname[51];
	float price;
	int typePassenger;
	char flycode[10];

	for(int i=0;i<len;i++)
	{
		if(list[i].isEmpty == FALSE)
		{
			counter ++;
		}
	}

	if(counter == len)
	{
		return -1;
	}

	id = 0;

	printf("\nNombre: ");
	scanf("%s", name);

	printf("\nApellido: ");
	scanf("%s", lastname);

	do{ printf("\nPrecio: ");
	}while(validarFloat("%f", &price) == 1);

	PedirAlfanumerico(flycode,"\nCodigo de vuelo: ");

	if(utn_getNumero(&typePassenger, "\nTipo de pasajero:\n1. Economica.\n2. Turista."
			"						  \n3. Primera Clase. \nIngrese: ", "\nERROR numero invalido.", 1, 3, 50) == 0)
	{
		printReturn(0);
	}
	else
	{
		printReturn(-1);
	}

	r = addPassenger(list, len, id, name, lastname, price, typePassenger, flycode);
	printReturn(r);

	return 0;
}

//===========================================================================

void printReturn(int r)
{
	if(r == 0)
	{
		printf("\nOK");
	}
	else
	{
		printf("\nERROR. Something was wrong.");
	}
}

//===========================================================================

int findPassengerById(Passenger list[], int len,int id)
{
	for(int i=0;i<len;i++)
	{
		if(list[i].id == id)
		{
			if(list[i].isEmpty == FALSE)
			{
				return i;
			}
			else
			{
				printf("Posiblemente el pasajero se encuentre vacio.");
				return -1;
			}
		}
	}

	return -1;
}

//===========================================================================

int modifyPassenger(Passenger list[], int len)
{
	int r;
	int id;
	int option;
	char name[51];
	char lastname[51];
	float price;
	int typePassenger;
	char flycode[10];

	if(utn_getNumero(&id, "\nIngrese ID: ","\nERROR numero invalido", 1, 2000, 50) == 0)
	{
		printReturn(0);
	}
	else
	{
		printReturn(-1);
	}
	r = findPassengerById(list, len, id);

	if(r != -1)
	{
				do
				{

					if(utn_getNumero(&option, "\n1. Nombre\n2. Apellido\n3. Precio\n4. Tipo de pasajero\n"
							   "5. Codigo de vuelo\n0. LISTO","\nERROR. Numero invalido.", 0, 5, 50) == 0)
						{
							printReturn(0);
						}
						else
						{
							printReturn(-1);
						}

					switch(option)
					{
						case 1:
							printf("\nNombre: ");
							scanf("%s", name);
							strcpy(list[id].name, name);
							break;

						case 2:
							printf("\nApellido: ");
							scanf("%s", lastname);
							strcpy(list[id].lastname, lastname);
							break;

						case 3:
							do{ printf("\nPrecio: ");
								}while(validarFloat("%f", &price) == 1);
							list[id].price = price;
							break;

						case 4:
							if(utn_getNumero(&typePassenger, "\nTipo de pasajero:\n1. Economica.\n2. Turista."
										"					  \n3. Primera Clase. \nIngrese: ", "ERROR numero invalido.", 1, 3, 50) == 0)
								{
									printReturn(0);
								}
								else
								{
									printReturn(-1);
								}
							list[id].typePassenger = typePassenger;
							break;

						case 5:
							PedirAlfanumerico(flycode,"\nCodigo de vuelo: ");
							strcpy(list[id].flycode, flycode);
							break;

						case 0:
							printf("Todo correcto.");
							return 0;
							break;
					}
				}while(option != 0);
				return 0;
	}
	return -1;
}

//===========================================================================

int removePassenger(Passenger list[], int len, int id)
{
	int r;

	r = findPassengerById(list, len, id);

	if(r != -1)
	{
		list[id].isEmpty = TRUE;
		return 0;
	}

	printf("Posiblemente el pasajero se encuentre vacio.");
	return r;
}

//===========================================================================

void passFromTo(Passenger list[],int i, int j)
{
	char auxChar[20];
	int auxInt;
	float auxFloat;

					auxInt = list[i].id;
					list[i].id = list[j].id;
					list[j].id = auxInt;

					strcpy(auxChar,list[i].name);
					strcpy(list[i].name,list[j].name);
					strcpy(list[j].name,auxChar);

					strcpy(auxChar,list[i].lastname);
					strcpy(list[i].lastname,list[j].lastname);
					strcpy(list[j].lastname,auxChar);

					auxFloat = list[i].price;
					list[i].price = list[j].price;
					list[j].price = auxFloat;

					strcpy(auxChar,list[i].flycode);
					strcpy(list[i].flycode,list[j].flycode);
					strcpy(list[j].flycode,auxChar);

					auxInt = list[i].typePassenger;
					list[i].typePassenger = list[j].typePassenger;
					list[j].typePassenger = auxInt;
}

//===========================================================================

int sortPassengers(Passenger list[], int len, int order)
{
	int counter = 0;
	Passenger orderedList[len];

	for(int i=0;i<len;i++)
	{
		if(list[i].isEmpty == FALSE)
		{
			orderedList[i].id = list[i].id;
			strcpy(orderedList[i].name,list[i].name);
			strcpy(orderedList[i].lastname,list[i].lastname);
			orderedList[i].price = list[i].price;
			strcpy(orderedList[i].flycode,list[i].flycode);
			orderedList[i].typePassenger = list[i].typePassenger;
			orderedList[i].isEmpty = FALSE;
			counter++;
		}
	}

	//MENOR A MAYOR
	if(order == 1)
	{
		for(int i=0;i<counter-1;i++)
		{
			for(int j=i+1;j<counter;j++)
			{
				if(strcmp(orderedList[i].lastname,orderedList[j].lastname) >0)
				{
					passFromTo(orderedList,i,j);
				}

				if(strcmp(orderedList[i].lastname,orderedList[j].lastname) == 0)
				{
					if(orderedList[i].typePassenger >  orderedList[j].typePassenger)
					{
						passFromTo(orderedList,i,j);
					}
				}
			}
		}
	}
	else
	{
		for(int i=0;i<counter-1;i++)
		{
			for(int j=i+1;j<counter;j++)
			{
				if(strcmp(orderedList[i].lastname,orderedList[j].lastname) <0)
				{
					passFromTo(orderedList,i,j);
				}

				if(strcmp(orderedList[i].lastname,orderedList[j].lastname) == 0)
				{
					if(orderedList[i].typePassenger <  orderedList[j].typePassenger)
					{
						passFromTo(orderedList,i,j);
					}
				}
			}
		}
	}

	printPassengers(orderedList, counter);

	return 0;
}

//===========================================================================

void printPassengers(Passenger list[], int len)
{
	printf("\n--ID-------NAME--------LASTNAME-----PRICE-----FLYCODE---TYPE-");
	for(int i=0;i<len;i++)
	{
		if(list[i].isEmpty == FALSE)
		{
			printf("\n------------------------------------------------------------");
			printf("\n| %-4d | %-10s | %-10s | %-10.2f | %-6s | %-1d |", list[i].id,list[i].name,list[i].lastname, list[i].price,list[i].flycode, list[i].typePassenger);
		}
	}
			printf("\n¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯");
}

//===========================================================================

int totalAndAveragePrice(Passenger list[], int len)
{
	int counter = 0;
	float acc = 0;
	float average;
	int counterHigher = 0;

	for(int i=0;i<len;i++)
	{
		if(list[i].isEmpty == FALSE)
		{
			counter++;
			acc = acc+list[i].price;
		}
	}

	if(counter ==0)
	{
		return -1;
	}

	printf("\nTotal: %.2f", acc);

	average = acc/counter;
	printf("\nPromedio: %.2f", average);

	for(int i=0;i<len;i++)
	{
		if(list[i].isEmpty == FALSE && list[i].price > average)
		{
			counterHigher ++;
		}
	}

	printf("\nSuperiores al promedio: %d", counterHigher);

	return 0;
}

//===========================================================================

int sortPassengersByCode(Passenger list[], int len, int order)
{
	int counter = 0;
	Passenger orderedList[len];

		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				orderedList[i].id = list[i].id;
				strcpy(orderedList[i].name,list[i].name);
				strcpy(orderedList[i].lastname,list[i].lastname);
				orderedList[i].price = list[i].price;
				strcpy(orderedList[i].flycode,list[i].flycode);
				orderedList[i].typePassenger = list[i].typePassenger;
				orderedList[i].isEmpty = FALSE;
				counter++;
			}
		}

		if(order == 1)
		{
			for(int i=0;i<counter-1;i++)
			{
				for(int j=i+1;j<counter;j++)
				{
					if(strcmp(orderedList[i].flycode,orderedList[j].flycode) >0)
					{
						passFromTo(orderedList,i,j);
					}

					if(strcmp(orderedList[i].flycode,orderedList[j].flycode) == 0)
					{
						if(orderedList[i].statusFlight > orderedList[j].statusFlight)
						{
							passFromTo(orderedList,i,j);
						}
					}
				}
			}
		}
			else
			{
				for(int i=0;i<counter-1;i++)
				{
					for(int j=i+1;j<counter;j++)
					{
						if(strcmp(orderedList[i].flycode,orderedList[j].flycode) <0)
						{
							passFromTo(orderedList,i,j);
						}

						if(strcmp(orderedList[i].flycode,orderedList[j].flycode) == 0)
						{
							if(orderedList[i].statusFlight <  orderedList[j].statusFlight)
							{
								passFromTo(orderedList,i,j);
							}
						}
					}
				}
			}

	printPassengers(orderedList, counter);


	return 0;
}

//===========================================================================
