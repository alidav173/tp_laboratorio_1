#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
		Passenger* pPasajero;
		char id[50];
		char nombre[50];
		char apellido[50];
		char precio[50];
		char tipoPasajero[50];
		char codigoVuelo[50];
		char statusFlight[50];
		char idTitulo[50];
		char nombreTitulo[50];
		char apellidoTitulo[50];
		char precioTitulo[50];
		char tipoPasajeroTitulo[50];
		char codigoVueloTitulo[50];
		char statusFlighTitulo[50];
		int primerElemento = 1;
		int lastId = 0;

		if(pFile !=NULL){
			while(!feof(pFile)){

				  if(primerElemento == 1){ //Leo la primera linea del archivo (header)
					fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idTitulo,nombreTitulo,apellidoTitulo,precioTitulo,codigoVueloTitulo,tipoPasajeroTitulo,statusFlighTitulo);
					primerElemento = 0;
					}

		         //leo las siguientes lineas del archivo csv
					fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,statusFlight);
					pPasajero = Passenger_newParametros(id,nombre,tipoPasajero);
					if(pPasajero !=NULL){
					ll_add(pArrayListPassenger,pPasajero);
					lastId = atoi(id);
					}
	     	}
		}
	    return lastId;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

	Passenger* pPasajero;
	int retorno = -1;
	if(pFile != NULL){
		while(!feof(pFile)){ //mientras no sea el final del archivo, entro en el bucle

		pPasajero = Passenger_new();
			if(fread(pPasajero,sizeof(Passenger),1,pFile) == 1){
				ll_add(pArrayListPassenger,pPasajero);
				retorno = 0;
			}
		}

	}
    return retorno;
}
