/*
 * menu.c
 *
 *  Created on: 9 jun. 2022
 *      Author: Alí Ansidey
 */


#include "menu.h"


/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

void mostrarMenu1(){
	printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n");
	printf("2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)\n");
	printf("3. Alta de pasajero\n");
	printf("4. Modificar datos de pasajero\n");
	printf("5. Baja de pasajero\n");
	printf("6. Listar pasajeros\n");
	printf("7. Ordenar pasajeros\n");
	printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n");
	printf("9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario)\n");
	printf("10. Salir\n");

}

void mostrarMenu2(){
	printf("Datos del pasajero a modificar: \n");
	printf("1. Nombre\n");
	printf("2. Apellido\n");
	printf("3. Tipo de pasajero\n");
	printf("4. Precio del ticket\n");
	printf("5. Codigo del vuelo\n");
	printf("6. Salir\n");
}

