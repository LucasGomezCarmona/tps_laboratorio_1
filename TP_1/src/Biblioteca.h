/*
 * Biblioteca.h
 *
 *  Created on: 11 abr. 2022
 *      Author: Lucas
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

/// @brief Funcion que permite el ingreso de un entero para elegir una opcion del menu (1-6).
/// @param Char mensaje que desea mostrar al usuario.
/// @param Int Rango minimo.
/// @param Int Rango maximo.
/// @return Int retorna el numero entero ingresado por el usuario.
int IngresarEnteroMinMax(char[], int, int);

//=============================================================================================================

/// @brief Funcion que permite el ingreso de un entero validando con un rango minimo (1).
/// @param Char mensaje que desea mostrar al usuario.
/// @param Int Rango minimo.
/// @return Int retorna el numero entero ingresado por el usuario.
int IngresarEnteroMin(char[], int);

//=============================================================================================================

/// @brief Funcion que permite el ingreso de un flotante validando con un rango minimo (1).
/// @param Char Mensaje que desea mostrar al usuario.
/// @param Int Rango minimo.
/// @return Float Retorna el numero flotante ingresado por el usuario.
float IngresarFlotanteMin(char[], int);

//=============================================================================================================

/// @brief Funcion que realiza un descuento sobre un valor.
/// @param Float Valor.
/// @param Float Descuento.
/// @return Float Valor con el descuento realizado.
float CalcularDescuento(float, float);

//=============================================================================================================

/// @brief Funcion que realiza un recargo sobre un valor.
/// @param Float Valor.
/// @param Float Recargo.
/// @return Float Valor con recargo realizado.
float CalcularRecargo(float, float);

//=============================================================================================================

/// @brief Funcion que muestra el menu inicial;
void MostrarMenu(void);

//=============================================================================================================

/// @brief Funcion que limpia la consola.
void LimpiarConsola(void);

//=============================================================================================================

/// @brief Funcion que realiza una division entre dos flotantes y retorna el resultado.
/// @param Float Valor dividendo.
/// @param Float Valor divisor
/// @return Float Valor cociente.
float DividirDosFlotantes(float, float);

//=============================================================================================================

/// @brief Funcion que muestra en pantalla los resultados calculados.
/// @param Float Precio debito.
/// @param Float Precio credito.
/// @param Float Precio Bitcoin.
/// @param Float Precio Unitario.
void InformarResultados(float, float, float, float);

//=============================================================================================================

/// @brief Funcion que calcula la diferencia entre dos flotantes.
/// @param Float Valor flotante.
/// @param Float Valor flotante.
/// @return Float Diferencia entre flotantes.
float CalcularDiferencia(float, float);









#endif /* BIBLIOTECA_H_ */
