/*
 ============================================================================
 Name        : TP2.c
 Author      : Alí Ansidey
 Version     : 1.0.0
 Copyright   : Your copyright notice
 Description : TP2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAMANIO_ARRAY 2000



int main(void) {
	setbuf(stdout, NULL);

	int opcion, opcion1, opcion2, opcion3, opcion4,opcion5,opcion6, opcion7, orden, idBuscado;

	Passenger ArrayPassenger[TAMANIO_ARRAY];
	initPassengers(ArrayPassenger, TAMANIO_ARRAY);

	mostrarMenuUno();
	utn_getNumero(&opcion,"Ingrese una opción\n", "Reingrese una opción\n",1,5,3);
	do{
		switch(opcion){
		case 1:
			//Alta del usuario
			opcion1 =chargePassengerData(ArrayPassenger, TAMANIO_ARRAY);
			printf("\n %d",opcion1);
			break;
		case 2:
			//Modificación de los datos del usuario
			opcion2 =changePassengerData(ArrayPassenger, TAMANIO_ARRAY);
			printf("\n %d",opcion2);
			break;
		case 3:
			//Baja lógica del usuario
			utn_getNumero(&idBuscado,"\n Ingrese el id del pasajero a eliminar: ","\n Reingrese el id del pasajero a eliminar: ", 1, INT_MAX,3);
			opcion3 =removePassenger(ArrayPassenger, TAMANIO_ARRAY, idBuscado);
			printf("\n %d",opcion3);
			break;
		case 4:
			//Informes de los usuarios ingresados
			mostrarMenuTres();
			utn_getNumero(&opcion4,"Ingrese una opción", "Reingrese una opción",1,3,3);
			switch(opcion4){
			case 1:
				//Listado de pasajeros ordenados alfabeticamente por apellido y tipo de pasajero
				utn_getNumero(&orden,"Ordeamiento [-1 Ascedente / 1 Descendente]\n", "Reingrese un ordenamiento  [-1 Ascedente / 1 Descendente]\n",-1,1,3);
				opcion5 = sortPassengers(ArrayPassenger, TAMANIO_ARRAY, orden);
				printf("\n %d", opcion5);
				break;
			case 2:
				//Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio
				opcion6 = informes2(ArrayPassenger,TAMANIO_ARRAY);
				printf("\n %d", opcion6);
				break;
			case 3:
				//Listado de los pasajeros por Código de vuelo y estos de vuelos "ACTIVO"
				opcion7 = informes3(ArrayPassenger,TAMANIO_ARRAY);
				printf("\n %d", opcion7);
				break;
			}
			break;
		}
		mostrarMenuUno();
		utn_getNumero(&opcion,"Ingrese una opción\n", "Reingrese una opción\n",1,5,3);

	}while(opcion !=5);

	puts("\n Ha salido del sistema");

	return 0;
}
