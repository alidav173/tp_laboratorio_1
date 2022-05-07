/*
 * arrayPassenger.c
 *
 *  Created on: 28 abr. 2022
 *      Author: Alí Ansidey
 */

#include "arrayPassenger.h"
#define EMPTY 0
#define ERROR -1
#define FULL 1
#define ACTIVO 4
#define INACTIVO 5

static int id =1;

static int generarId();

static int generarId(){
	return id++;
}


int initPassengers(Passenger* list, int len){
    int retorno = ERROR;
    int i;
    if(list != NULL && len >0){
    	for(i =0; i<len;i++){
    		list[i].isEmpty = EMPTY;
    	}
    	retorno = 0;
    }

    return retorno;
}

int findFirstSpace (Passenger* list, int len){
	int index = ERROR;
	int i;
	for(i = 0; i < len; i++){
		if(list[i].isEmpty == EMPTY){
			index = i;
			break;
		}
	}
return index;
}


int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[]){
     int retorno = ERROR;
     int index = findFirstSpace(list, len);
     Passenger pasajeroNuevo;
     if(index != ERROR && list != NULL && len > 0 ){
    	 pasajeroNuevo.id = id;
    	 strcpy(pasajeroNuevo.name, name);
    	 strcpy(pasajeroNuevo.lastName, lastName);
    	 pasajeroNuevo.price = price;
    	 pasajeroNuevo.typePassenger = typePassenger;
    	 strcpy(pasajeroNuevo.flycode,flycode);
    	 pasajeroNuevo.statusFlight = ACTIVO;
    	 pasajeroNuevo.isEmpty = FULL;
    	 list[index] = pasajeroNuevo;
    	 retorno = 0;
     }

    return retorno;
}

int chargePassengerData(Passenger* list, int len){
	int retorno = -1;
	Passenger pasajeroNuevo;
	if(list != NULL && len > 0){
		pasajeroNuevo.id = generarId();
		utn_getNombre(pasajeroNuevo.name, 51,"\n Ingrese el nombre del pasajero: ","\n Reingrese el nombre del pasajero: ",3);
		utn_getNombre(pasajeroNuevo.lastName, 51,"\n Ingrese el apellido del pasajero: ","\n Reingrese el apellido del pasajero: ",3);
		utn_getNumeroFlotante(&pasajeroNuevo.price,"\n Ingrese el precio del ticket: ","\n Ingrese el precio del ticket: ", 0, INT_MAX,3);
		utn_getCadena(pasajeroNuevo.flycode, 10,"\n Ingrese el codigo del vuelo: ","\n Reingrese el codigo del vuelo: ",3);
		utn_getNumero(&pasajeroNuevo.typePassenger,"\n Ingrese el tipo de pasajero [1 - Turista/ 2- BUSSINESS / 3 - FIRST]\n","\n Ingrese el tipo de pasajero [1 - Turista/ 2- BUSSINESS / 3 - FIRST]\n", 1, 3, 3);
		if(addPassenger(list,len, pasajeroNuevo.id, pasajeroNuevo.name,pasajeroNuevo.lastName,pasajeroNuevo.price,pasajeroNuevo.typePassenger, pasajeroNuevo.flycode) != ERROR){
			puts("\n Se cargaron los datos del pasajero con exito");
			retorno = 0;
		}
		else{
			puts("\n NO se pudieron cargar los datos del pasajero\n");
		}
	}
	return retorno;
}


int changePassengerData(Passenger* list, int len){
	int retorno = -1;
	int idBuscado, opcion, indice;
	printPassenger(list,len);
	utn_getNumero(&idBuscado,"\n Ingrese el id del pasajero a modificar: ","\n Reingrese el id del pasajero a modificar: ", 1, INT_MAX,3);
	indice = findPassengerById(list,len,idBuscado);
	if(indice!= ERROR){
		mostrarMenuDos();
		utn_getNumero(&opcion,"\n Ingrese la opcion a modificar: ","\n Reingrese la opcion a modificar: ", 1,6,3);
		switch(opcion){
		case 1:
			utn_getNombre(list[indice].name, 51,"\n Ingrese el nombre del pasajero: ","\n Reingrese el nombre del pasajero: ",3);
				break;
		case 2:
			utn_getNombre(list[indice].lastName, 51,"\n Ingrese el apellido del pasajero: ","\n Reingrese el apellido del pasajero: ",3);
			break;
		case 3:
			utn_getNumeroFlotante(&list[indice].price,"\n Ingrese el precio del ticket: ","\n Ingrese el precio del ticket: ", 0, 1000000,3);
			break;
		case 4:
			utn_getCadena(list[indice].flycode, 10,"\n Ingrese el codigo del vuelo: ","\n Reingrese el codigo del vuelo: ",3);
			break;
		case 5:
			utn_getNumero(&list[indice].typePassenger,"\n Ingrese el tipo de pasajero [1 - Turista/ 2- BUSSINESS / 3 - FIRST]\n","\n Ingrese el tipo de pasajero [1 - Turista/ 2- BUSSINESS / 3 - FIRST]\n", 1, 3, 3);
			break;
		case 6:
			utn_getNumero(&list[indice].statusFlight ,"\n Ingrese el estado del vuelo [4 - ACTIVO / 5 - INACTIVO]\n","\n Reingrese el estado del vuelo [4 - ACTIVO / 5 - INACTIVO]\n", 4, 5, 3);
		}
		retorno = 0;

	}
	return retorno;
}


int findPassengerById(Passenger* list, int len,int id){
    int retorno = -1;
    int i;
    for(i= 0; i < len; i++){
    	if(list[i].id == id){
    		retorno = i;
    		break;
    	}
    }
    return retorno;
}

int removePassenger(Passenger* list, int len, int id){
    char respuesta[3];
	int retorno = -1;
    int indice;
    	printPassenger(list,len);
    	indice = findPassengerById(list,len,id);
    	utn_getNombre(respuesta, 3,"\n Esta seguro de eliminar al pasajero: [si/no]","\n Reingrese su opción [si/no]: ",3);
    	strMinuscula(respuesta);
    	if(indice != -1 && strcmp(respuesta,"si")== 0){
    		list[indice].isEmpty = EMPTY;
    		retorno = 0;
    	}

    return retorno;
}

int printPassenger(Passenger* list, int length){
    int retorno = -1;
    int i;
    if(list != NULL && length > 0){
    	printf("\nListado de pasajeros:");
    	for(i=0; i < length; i++){
    		if(list[i].isEmpty != EMPTY){
    		showPassengerData(list[i]);
    	}
    }
    	retorno = 0;
    }

    return retorno;
}

int sortPassengers(Passenger* list, int len, int order){
     int retorno = -1;
     int i, j;
     /* case -1 -> menor a mayor (ascendente)
      * case 1 -> mayor a menor (descendente)
      *
      */
     Passenger pasajeroAux;
     if(list != NULL && len > 0){
    	 switch(order){
    	 case -1:
    		 for(i= 0; i < len-1; i++){
    			 for(j=i+1; j < len; j++){
    				 //Compruebo que los pasajeros no esten eliminados del sistema
    				 if(list[i].isEmpty == FULL && list[j].isEmpty == FULL){
    					 if(strcmp(list[i].lastName,list[j].lastName) > 0 ){
    						 //Intercambio de posiciones en el array
    						 pasajeroAux = list[i];
    						 list[i] = list[j];
    						 list[j] = pasajeroAux;
    					 }
    					 else if(strcmp(list[i].lastName,list[j].lastName) == 0 && list[i].typePassenger > list[j].typePassenger){
    						 //Intercambio de posiciones en el array
    						 pasajeroAux = list[i];
    						 list[i] = list[j];
    						 list[j] = pasajeroAux;
    					 }
    				 }
    			 }
    		 }
    		 retorno = 0;
    		 printPassenger(list, len);
    		 break;

    	 case 1:
    		 for(i= 0; i < len-1; i++){
    	    			 for(j=i+1; j < len; j++){
    	    				 if(list[i].isEmpty == FULL && list[j].isEmpty == FULL){
    	    					 if(strcmp(list[i].lastName,list[j].lastName ) < 0){
    	    						 //Intercambio de posiciones en el array
    	    						 pasajeroAux = list[i];
    	    						 list[i] = list[j];
    	    						 list[j] = pasajeroAux;
    	    					 }
    	    					 else if(strcmp(list[i].lastName,list[j].lastName) == 0 && list[i].typePassenger < list[j].typePassenger){
    	    						 //Intercambio de posiciones en el array
    	    						 pasajeroAux = list[i];
    	    						 list[i] = list[j];
    	    						 list[j] = pasajeroAux;
    	    					 }
    	    				 }
    	    			 }
    	    		 }
      		 retorno = 0;
      		printPassenger(list, len);
        		 break;

    	 }

     }

    return retorno;
}

void showPassengerData(Passenger passenger){
	printf("\n Id: %d,\t Nombre del pasajero %s,\t  Apellido del pasajero: %s,\t Precio del ticket $ %.2f, \t Codigo del vuelo: %s,\t Tipo de pasajero: %d,\t, Estado del vuelo: %d",passenger.id,passenger.name, passenger.lastName, passenger.price, passenger.flycode, passenger.typePassenger, passenger.statusFlight);

}



