/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Alí Ansidey
 */

#include "Passenger.h"

Passenger* Passenger_new(){
	Passenger *passengerNew;
	passengerNew = (Passenger*) calloc(sizeof(Passenger),0);
	return passengerNew;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr){
	Passenger* passengerNew = Passenger_new();
	int id, tipoPas;
	char nombre[50];

	//Parseo el id
	id = atoi(idStr);
	strcpy(nombre,nombreStr);

	if(tipoPasajeroStr != NULL){
		//Preguntar que hacer con tipo de pasajero
		if(strcmp(tipoPasajeroStr,"FirstClass")== 0){
			tipoPas = 3;
		}
		else if(strcmp(tipoPasajeroStr,"ExecutiveClass")== 0){
			tipoPas = 2;
		}
		else if(strcmp(tipoPasajeroStr,"EconomyClass")== 0){
			tipoPas = 1;
		}
		else{
			tipoPas = 0;
		}
	}

	if(idStr != NULL && nombreStr != NULL && tipoPasajeroStr != NULL){
		Passenger_setId(passengerNew, id);
		Passenger_setNombre(passengerNew,nombre);
		Passenger_setTipoPasajero(passengerNew,tipoPas);
	}
	return passengerNew;
}


int Passenger_delete(Passenger* this){
	int retorno = -1;
	if(this != NULL){
		free(this);
		retorno = 0;
	}
	return retorno;
}


int Passenger_setId(Passenger* this,int id){
	int retorno = -1;
	if(this != NULL && id>0){
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

int Passenger_getId(Passenger* this,int* id){
	int retorno = -1;
	if(this !=NULL && id !=NULL){
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre){
	int retorno = -1;
	if(this != NULL && nombre != NULL){
		strcpy(this->nombre,nombre);
		retorno = 0;
	}
	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre){
	int retorno = -1;
	if(this != NULL && nombre != NULL){
		strcpy(nombre,this->nombre);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido){
	int retorno= -1;
	if(this != NULL && apellido != NULL){
		strcpy(this->apellido,apellido);
		retorno = 0;
}
	return retorno;
}


int Passenger_getApellido(Passenger* this,char* apellido){
	int retorno = -1;
	if(this != NULL && apellido != NULL){
		strcpy(apellido,this->apellido);
		retorno =0;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL){
		strcpy(this->codigoVuelo,codigoVuelo);
		retorno = 0;
	}

	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL){
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero){
	int retorno = -1;
	if(this != NULL && tipoPasajero > -1 ){
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}

	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero){
	int retorno = -1;
	if(this !=NULL && tipoPasajero !=NULL){
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio){
	int retorno = -1;
	if(this != NULL && precio >0){
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio){
	int retorno = -1;
	if(this != NULL && precio != NULL){
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}

int Passenger_searchById(LinkedList* pArrayListPassenger, int id){
    int retorno = -1;
    int i;
    int idPasajero;
    Passenger* pPasajero;
    int len = ll_len(pArrayListPassenger);
    for(i= 0; i < len; i++){
    	pPasajero = ll_get(pArrayListPassenger, i);
    	if(Passenger_getId(pPasajero,&idPasajero) == 0 && (idPasajero == id)){
    		retorno = i;
    		break;
    	}
    }
    return retorno;
}

int Passenger_getAllInfo(Passenger* this){
	int retorno = -1;
	if(this != NULL){
		int id;
		char nombre[50];
		char apellido[50];
		int tipoPas;
		float precio;
		char codigoVuelo[4];

		//obtengo todos los datos del pasajero
		Passenger_getId(this,&id);
		Passenger_getNombre(this,nombre);
		Passenger_getApellido(this,apellido);
		Passenger_getTipoPasajero(this,&tipoPas);
		Passenger_getCodigoVuelo(this,codigoVuelo);
		Passenger_getPrecio(this,&precio);
		printf("id: %d - nombre: %s - apellido %s - tipoPas: %d -  precio ticket: %.2f  - codigo vuelo: %s\n",id,nombre,apellido,tipoPas,precio,codigoVuelo);
		retorno = 0;
	}
	return retorno;
}


int Passengers_getAllList(LinkedList* pArrayListPassenger){
	int retorno = -1;
	int len = ll_len(pArrayListPassenger);
	if(pArrayListPassenger != NULL){
		Passenger* pPasajeroBuscado;
		int len = ll_len(pArrayListPassenger);
		int i = 0;
		if(len > 0){
			for(i = 0; i < len; i++){
				pPasajeroBuscado = ll_get(pArrayListPassenger,i);
				Passenger_getAllInfo(pPasajeroBuscado);
				retorno = 0;
			}
	}

}
	return retorno;
}


