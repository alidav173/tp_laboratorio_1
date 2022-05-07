/*
 * arrayPassenger.h
 *
 *  Created on: 28 abr. 2022
 *      Author: Alí Ansidey
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "inputs.h"

//Estructura Passenger
 typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float price;
    char flycode[10];
    int typePassenger;
    int statusFlight;
    int isEmpty;
}Passenger;




/*,
*Carga los datos de un pasajero
*Retorna -1 si hay error y 0 si todo ok
*Parametro 1: lista de pasajeros
*Parametro 2: tamaño del array de Pasajeros
*/


int chargePassengerData(Passenger* list, int len);




/*,
*Inicializa la lista de pasajeros con isEmpty = VACIO
*Retorna -1 si hay error y 0 si todo ok
*Parametro 1: lista de pasajeros
*Parametro 2: tamaño del array de Pasajeros
*/

int initPassengers(Passenger* list, int len);



/*
*Busca el primer espacio vacio del array de pasajeros
*Retorna -1 si hay error y el indice del array vacio si todo ok
*Parametro 1: lista de pasajeros
*Parametro 2: tamaño del array de Pasajeros
*/

int findFirstSpace (Passenger* list, int len);




/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1)
*
*/


int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[]);





/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len,int id);





/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id);




/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order);




/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger* list, int length);




/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order);


/*
*
* Muestra los datos de un pasajero
* Recibe como parametro un pasajero
* No retorna nada
*/


void showPassengerData(Passenger passenger);

/*
*
* Cambia los datos de un pasajero
* Recibe como parametro 1: lista de pasajero
* Recibe como parametro 2: tamaño del array
* Retorna -1 si hay error y 0 si todo ok
*
*/



int changePassengerData(Passenger* list, int len);


#endif /* ARRAYPASSENGER_H_ */
