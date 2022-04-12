/*
 ============================================================================
 Name        : TP_1.c
 Author      : Lucas Fernando Gomez Carmona
 Description : Trabajo Practico 1 (Laboratorio I)
1. Ingresar Kilómetros: ( km=x)
2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
	- Precio vuelo Aerolíneas:
	- Precio vuelo Latam:
3. Calcular todos los costos:
	a) Tarjeta de débito (descuento 10%)
	b) Tarjeta de crédito (interés 25%)
	c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
	d) Mostrar precio por km (precio unitario)
	e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
4. Informar Resultados
	“Latam:
	a) Precio con tarjeta de débito: r
	b) Precio con tarjeta de crédito: r
	c) Precio pagando con bitcoin : r
	d) Precio unitario: r
	Aerolíneas:
	a) Precio con tarjeta de débito: r
	b) Precio con tarjeta de crédito: r
	c) Precio pagando con bitcoin : r
	d) Precio unitario: r
	La diferencia de precio es : r “
	5. Carga forzada de datos
	6. Salir
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

int main(void)
{
	setbuf(stdout, NULL);
	int opcionIngresada;
	int kilometrosIngresados;
	float precioIngresadoLatam;
	float precioIngresadoAerolineas;
	float precioDebitoLatam;
	float precioCreditoLatam;
	float precioBitcoinLatam;
	float precioUnitarioLatam;
	float precioDebitoAerolineas;
	float precioCreditoAerolineas;
	float precioBitcoinAerolineas;
	float precioUnitarioAerolineas;
	float diferenciaDePrecio;
	int banderaKm;
	int banderaPrecios;

	banderaKm=0;
	banderaPrecios=0;

	do
	{
		MostrarMenu();
		opcionIngresada=IngresarEnteroMinMax("Ingrese una opcion: ", 1, 6);

		switch(opcionIngresada)
		{
			case 1:
				kilometrosIngresados=IngresarEnteroMin("Ingrese los Kilometros: ", 1);
				banderaKm=1;
				LimpiarConsola();
				break;

			case 2:
				precioIngresadoAerolineas=IngresarFlotanteMin("Ingrese los precios de los vuelos.\n- Precio vuelo Aerolineas: $", 1);
				precioIngresadoLatam=IngresarFlotanteMin("- Precio vuelo Latam: $", 1);
				banderaPrecios=1;
				LimpiarConsola();
				break;

			case 3:
					if(banderaPrecios==1 && banderaKm==1)
					{
						printf("Calculando...\n");
						precioDebitoLatam=CalcularDescuento(precioIngresadoLatam, 10);
						precioCreditoLatam=CalcularRecargo(precioIngresadoLatam, 25);
						precioBitcoinLatam=DividirDosFlotantes(precioIngresadoLatam, 4606954.55);
						precioUnitarioLatam=DividirDosFlotantes(precioIngresadoLatam, kilometrosIngresados);
						precioDebitoAerolineas=CalcularDescuento(precioIngresadoAerolineas, 10);
						precioCreditoAerolineas=CalcularRecargo(precioIngresadoAerolineas, 25);
						precioBitcoinAerolineas=DividirDosFlotantes(precioIngresadoAerolineas, 4606954.55);
						precioUnitarioAerolineas=DividirDosFlotantes(precioIngresadoAerolineas, kilometrosIngresados);
						diferenciaDePrecio=CalcularDiferencia(precioIngresadoLatam, precioIngresadoAerolineas);
					}
					LimpiarConsola();
				break;

			case 4:
				if(banderaPrecios==1 && banderaKm==1)
				{
					printf("Latam:\n");
					InformarResultados(precioDebitoLatam, precioCreditoLatam, precioBitcoinLatam, precioUnitarioLatam);
					printf("Aerolineas:\n");
					InformarResultados(precioDebitoAerolineas, precioCreditoAerolineas, precioBitcoinAerolineas, precioUnitarioAerolineas);
					printf("La diferencia de precio es: $%.2f", diferenciaDePrecio);
				}
				LimpiarConsola();
				break;

			case 5:
				printf("Calculando...\n");
				precioDebitoLatam=CalcularDescuento(159339, 10);
				precioCreditoLatam=CalcularRecargo(159339, 25);
				precioBitcoinLatam=DividirDosFlotantes(159339, 4606954.55);
				precioUnitarioLatam=DividirDosFlotantes(159339, 7090);
				precioDebitoAerolineas=CalcularDescuento(162965, 10);
				precioCreditoAerolineas=CalcularRecargo(162965, 25);
				precioBitcoinAerolineas=DividirDosFlotantes(162965, 4606954.55);
				precioUnitarioAerolineas=DividirDosFlotantes(162965, 7090);
				diferenciaDePrecio=CalcularDiferencia(159339, 162965);
				printf("KMs Ingresados: 7090km\n");
				printf("Precio Aerolineas: $162965\n");
				InformarResultados(precioDebitoAerolineas, precioCreditoAerolineas, precioBitcoinAerolineas, precioUnitarioAerolineas);
				printf("\nPrecio Latam: $159339\n");
				InformarResultados(precioDebitoLatam, precioCreditoLatam, precioBitcoinLatam, precioUnitarioLatam);
				printf("\nLa diferencia de precio es: $%.2f\n", diferenciaDePrecio);
				LimpiarConsola();
				break;

			default:
				printf("Hasta pronto!");
				LimpiarConsola();
				break;
		}
	}
	while(opcionIngresada!=6);
	return EXIT_SUCCESS;
}
