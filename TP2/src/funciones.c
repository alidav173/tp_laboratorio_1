/*
 * funciones.c
 *
 *  Created on: 28 abr. 2022
 *      Author: Alí Ansidey
 */
#include "funciones.h"
#define ERROR -1
#define EMPTY 0
#define ACTIVO 4

void mostrarMenuUno(){
	printf("\n Menú:\n");
	printf("1. ALTA PASAJERO: \n");
	printf("2. MODIFICAR PASAJERO: \n");
	printf("3. BAJA PASAJERO: \n");
	printf("4. INFORMES: \n");
	printf("5. HARDCODEO: \n");
	printf("6. SALIR: \n");

}

void mostrarMenuDos(){
	printf("\n Elija una de las opciones a modificar:\n");
	printf("1. Nombre del pasajero: \n");
	printf("2. Apellido del pasajero: \n");
	printf("3. Precio del vuelo: \n");
	printf("4. Código del vuelo: \n");
	printf("5. Tipo de pasajero: \n");
	printf("6. Estado del vuelo: \n");

}

void mostrarMenuTres(){
	printf("\n Informar:\n");
	printf("1. Listado de pasajeros ordenados alfabeticamente por Apellido y Tipo: \n");
	printf("2. Total y promedio de pasajes y cuantos pasajeros superan el promedio: \n");
	printf("3. Listado de pasajeros con Codigo de vuelo y estado Activo: \n");
}

float sumadorPrecio(Passenger* list, int len){
	float suma=0;
	int i;
	if(list != NULL && len >0){
		for(i=0; i< len; i++){
			if(list[i].isEmpty != EMPTY){
				suma += list[i].price;
			}
		}
	}
return suma;
}

int cantidadPasajerosActivo(Passenger* list, int len){
	int suma=0;
	int i;
	if(list != NULL && len >0){
		for(i=0; i< len; i++){
			if(list[i].isEmpty != EMPTY){
				suma++;
			}
		}
	}
return suma;
}


float calcularPromedio(float suma, int cantidad){
	float promedio = 0;
	if(cantidad >0){
		promedio = suma /cantidad;
	}
	return promedio;
}

int mayoresAlpromedio(Passenger* list, int len, float promedio){
	int retorno = 0;
	int i;
	if(list != NULL && len > 0 && promedio > 0){
		for(i=0; i < len; i++){
			if(list[i].isEmpty != EMPTY && list[i].price > promedio){
				retorno ++;
			}
		}
	}
	return retorno;
}

int informes2(Passenger* list, int len){
	int retorno = ERROR;
	float suma, promedio;
	int pasajeroSupPro, cantPasj;
	if(list != NULL && len >0 ){
		 suma = sumadorPrecio(list,len);
		 cantPasj = cantidadPasajerosActivo(list,len);
		 promedio = calcularPromedio(suma,cantPasj);
			printf("\n El total de los pasajes fue: %.2f", suma);
			printf("\n El promedio de los pasajes fue: %.2f", promedio);
		 if(promedio > 0){
			 pasajeroSupPro = mayoresAlpromedio(list,len,promedio);
				printf("\n La cantidad de pasajeros que superan el precio promedio: %d",pasajeroSupPro);
		 }
		retorno = 0;
	}
	return retorno;
}

int informes3(Passenger* list, int len){
	int retorno = ERROR;
	int i;
	if(list != NULL && len >0){
		for(i=0; i < len; i++){
			if(list[i].isEmpty != EMPTY && list[i].statusFlight == ACTIVO ){
			showPassengerData(list[i]);
			}
		}
		retorno = 0;
	}
return retorno;
}

