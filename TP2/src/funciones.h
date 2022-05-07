/*
 * funciones.h
 *
 *  Created on: 28 abr. 2022
 *      Author: Alí Ansidey
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include "arrayPassenger.h"
#include "inputs.h"

/*
 * Muestra el menu 1 del main del programa
 * No retorna nada
 */

void mostrarMenuUno();

/*
 * Muestra el menu 2 del main del programa
 * No retorna nada
 */

void mostrarMenuDos();

/*
 * Muestra el menu 3 del main del programa
 * No retorna nada
 */


void mostrarMenuTres();

/*
 * Suma los precios de los pasajes de los pasajeros
 * Retorna un numero mayor a 0 si todo ok
 * Parametro 1: lista de pasajeros
 * Parametro 2: tamaño del array
 */


float sumadorPrecio(Passenger* list, int len);

/*
 * Retorna la cantidad de pasajeros con atributo isEmpty == ACTIVO
 * Retorna un numero mayor a 0 si todo ok
 * Parametro 1: lista de pasajeros
 * Parametro 2: tamaño del array
 */

int cantidadPasajerosActivo(Passenger* list, int len);

/*
 * Retorna el promedio de los valores
 * Retorna un numero mayor a 0 si todo ok
 * Parametro 1: numero flotante
 * Parametro 2: numero entero
 */

float calcularPromedio(float suma, int cantidad);

/*
 * Retorna la cantidad de pasajeros Mayores al promedio de precios
 * Retorna un numero mayor a 0 si todo ok
 * Parametro 1: lista de pasajeros
 * Parametro 2: tamaño del array
 * Parametro 3: numero flotante de referencia (promedio)
 */


int mayoresAlpromedio(Passenger* list, int len, float promedio);


/*
 * Imprime el informe de precio promedio de los tickets, pasajeros que superan
 * el precio promedio y el total de los tickets
 * Retorna -1 si hay error y 0 si todo ok
 * Parametro 1: lista de pasajeros
 * Parametro 2: tamaño del array
 */

int informes2(Passenger* list, int len);


/*
 * Imprime los pasajeros con estado de vuelo "ACTIVO"
 * Retorna -1 si hay error y 0 si todo ok
 * Parametro 1: lista de pasajeros
 * Parametro 2: tamaño del array
 */

int informes3(Passenger* list, int len);


#endif /* FUNCIONES_H_ */
