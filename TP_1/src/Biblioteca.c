/*
 * Biblioteca.c
 *
 *  Created on: 11 abr. 2022
 *      Author: Lucas Fernando Gomez Carmona
 */
#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

int IngresarEnteroMinMax(char mensaje[], int minimo, int maximo)
{
	int numeroIngresado;

	do{
		printf("%s", mensaje);
		scanf("%d", &numeroIngresado);

	}while(numeroIngresado<minimo || numeroIngresado>maximo);

	return numeroIngresado;
}

//=============================================================================================================

int IngresarEnteroMin(char mensaje[], int minimo)
{
	int numeroIngresado;

	do{
		printf("%s", mensaje);
		scanf("%d", &numeroIngresado);

	}while(numeroIngresado<minimo);

	return numeroIngresado;
}

//=============================================================================================================

float IngresarFlotanteMin(char mensaje[], int minimo)
{
	int numeroIngresado;

	do{
		printf("%s", mensaje);
		scanf("%d", &numeroIngresado);

	}while(numeroIngresado<minimo);

	return numeroIngresado;
}

//=============================================================================================================

float CalcularDescuento(float precio, float descuento)
{
	int valorPorDescontar;
	int total;

	valorPorDescontar=(precio*descuento)/100;
	total=precio-valorPorDescontar;

	return total;
}

//=============================================================================================================

float CalcularRecargo(float precio, float recargo)
{
	int valorPorRecargar;
	int total;

	valorPorRecargar=(precio*recargo)/100;
	total=precio+valorPorRecargar;

	return total;
}

//=============================================================================================================

void MostrarMenu(void)
{
	printf("1. Ingresar Kilometros.\n2. Ingresar Precio de Vuelos. \n3. Calcular todos los costos.");
	printf("\n4. Informar Resultados.\n5. Carga forzada de datos.\n6. Salir\n");
}

//=============================================================================================================

void LimpiarConsola(void)
{
	printf("\n\n");
}

//=============================================================================================================

float DividirDosFlotantes(float valorDividendo, float valorDivisor)
{
	float valorCociente;

	valorCociente=valorDividendo/valorDivisor;

	return valorCociente;
}

void InformarResultados(float debito, float credito, float bitcoin, float unitario)
{
	printf("a) Precio con tarjeta de debito: $%.2f\n", debito);
	printf("b) Precio con tarjeta de credito: $%.2f\n", credito);
	printf("c) Precio pagando con Bitcoin: BTC %.6f\n", bitcoin);
	printf("d) Precio unitario: $%.2f\n", unitario);
}

//=============================================================================================================

float CalcularDiferencia(float primerValor, float segundoValor)
{
	float diferencia;
	if(primerValor>segundoValor)
	{
		diferencia=primerValor-segundoValor;
	}
	else
	{
		diferencia=segundoValor-primerValor;
	}
	return diferencia;
}
