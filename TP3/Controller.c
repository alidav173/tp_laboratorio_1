#include "Controller.h"

int static obtainID(int* id);

int* lastId;

/**
 * @brief  genera un id nuevo
 * solo puede ser llamada por una funcion de aca
 * @return	Retorna 0 si pudo, sino -1.
 */
int static obtainID(int* id){
	int newId;
	if(&id <=0){
		newId = 1;
	}
	else{
		newId = *id +1;
	}
	return newId;
}



/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int parser;
	FILE* pArchivo;
	if(access(path,F_OK)==0){
	pArchivo = fopen(path,"r");
	parser = parser_PassengerFromText(pArchivo,pArrayListPassenger);
	*lastId = parser;
	retorno = 0;
	}
	else{
		pArchivo =fopen(path,"w");
		retorno = 0;
	}
	fclose(pArchivo);
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE *pFile;
	int retorno = -1;
	pFile = fopen(path,"r");
	if(pFile != NULL){
		parser_PassengerFromBinary(pFile ,pArrayListPassenger);
		retorno = 0;
	}

	fclose(pFile);
    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    int id;
    char nombre[50];
    char apellido[50];
    float precio;
    int tipoPasajero;
    char codigoVuelo[4];
    Passenger* pPasenger;
    pPasenger=  Passenger_new();

    if(pArrayListPassenger != NULL && pPasenger != NULL){
    	id = obtainID(&lastId);
    	Passenger_setId(pPasenger,id);
    	//Ingreso y seteo el nombre del pasajero
    	utn_getNombre(nombre,50,"Ingrese el nombre del pasajero: \n","Reingrese el nombre: \n", 3);
    	Passenger_setNombre(pPasenger,nombre);

    	//Ingreso y seteo el apellido del pasajero
    	utn_getNombre(apellido,50,"Ingrese el apellido del pasajero: \n","Reingrese el apellido: \n", 3);
    	Passenger_setApellido(pPasenger,apellido);

    	//Ingreso y seteo el codigo de vuelo del pasajero
    	utn_getCadena(codigoVuelo,4,"Ingrese el codigo de vuelo: \n","Reingrese el codigo: \n", 3);
    	Passenger_setCodigoVuelo(pPasenger,codigoVuelo);

    	//Ingreso y seteo el codigo de vuelo del pasajero
    	utn_getNumero(&tipoPasajero,"Ingrese el tipo de pasajero [1 -EconomyClass, 2 -ExecutiveClass, 3 - FirstClass ] \n",
    			"Reigrese el tipo de pasajero [1 -EconomyClass, 2 -ExecutiveClass, 3 - FirstClass ] \n",1, 3, 3);
    	Passenger_setTipoPasajero(pPasenger, tipoPasajero);

    	//Ingreso y seteo el precio de vuelo
    	utn_getNumeroFlotante(&precio, "Ingrese el precio del vuelo: \n","Reingrese el precio: \n",0,10000000,3);
    	Passenger_setPrecio(pPasenger,precio);

    	//agrego el pasajero a lista de pasajeros
    	ll_add(pArrayListPassenger,pPasenger);
    	retorno = 0;
    }
	return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int id,len,index, opcionMenu;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char tipoPasajeroChar[50];
	char codigoVuelo[4];

	if(pArrayListPassenger != NULL){
		len = ll_len(pArrayListPassenger);
		if(len > 0){
			Passenger* pPasajeroBuscado;
			Passengers_getAllList(pArrayListPassenger);
			utn_getNumero(&id,"Ingrese el id del pasajero a buscar: \n","Reingrese el id del pasajero a buscar: \n",1, 100000, 3);
			index = Passenger_searchById(pArrayListPassenger,id);
			if(index >= 0){ //Si el indice es mayor a 0, modifico los datos del pasajero
				pPasajeroBuscado=  ll_get(pArrayListPassenger, index);
				mostrarMenu2();
				utn_getNumero(&opcionMenu,"Ingrese la opción: \n","Reingrese la opcion: \n",1,5,3);
				while(opcionMenu != 6){
					switch(opcionMenu){
					case 1: //modifico el nombre del pasajero
						Passenger_getNombre(pPasajeroBuscado,nombre);
						printf("Nombre: %s",nombre);
						utn_getNombre(nombre,50,"Ingrese el nuevo nombre: \n","Reingrese el nuevo nombre: \n", 3);
						Passenger_setNombre(pPasajeroBuscado,nombre);
						printf("Nuevo nombre: %s",nombre);
						break;

					case 2: //modifico el apellido del pasajero
						Passenger_getApellido(pPasajeroBuscado,apellido);
						printf("Nombre: %s",apellido);
						utn_getNombre(nombre,50,"Ingrese el nuevo apellido: \n","Reingrese el nuevo apellido: \n", 3);
						Passenger_setApellido(pPasajeroBuscado,apellido);
						printf("Nuevo apellido: %s",apellido);
						break;

					case 3: //modifico el tipo de pasajero
						Passenger_getTipoPasajero(pPasajeroBuscado,&tipoPasajero);
						if(tipoPasajero == 1){
							strcpy(tipoPasajeroChar,"EconomyClass");
						}
						else if(tipoPasajero == 2){
							strcpy(tipoPasajeroChar,"ExecutiveClass");
						}
						else if(tipoPasajero == 3){
							strcpy(tipoPasajeroChar,"FirstClass");

						}
						printf("tipoPasajero: %s",tipoPasajeroChar);
				    	utn_getNumero(&tipoPasajero,"Ingrese el nuevo tipo de pasajero [1 -EconomyClass, 2 -ExecutiveClass, 3 - FirstClass ] \n",
				    			"Reigrese el nuevo tipo de pasajero [1 -EconomyClass, 2 -ExecutiveClass, 3 - FirstClass ] \n",1, 3, 3);

				    	Passenger_setTipoPasajero(pPasajeroBuscado,tipoPasajero);
				    	break;

					case 4: //modifico el precio del vuelo
						Passenger_getPrecio(pPasajeroBuscado,&precio);
						printf("precio del ticket: %.2f",precio);
						utn_getNumeroFlotante(&precio, "Ingrese el precio del vuelo: \n","Reingrese el precio: \n",0,10000000,3);
						Passenger_setPrecio(pPasajeroBuscado,precio);
						printf("nuevo precio del ticket: %.2f",precio);
						break;
					case 5:
						Passenger_getCodigoVuelo(pPasajeroBuscado,codigoVuelo);
						printf("codigo del vuelo: %s",codigoVuelo);
				    	utn_getCadena(codigoVuelo,4,"Ingrese el codigo de vuelo: \n","Reingrese el codigo: \n", 3);
				    	Passenger_setCodigoVuelo(pPasajeroBuscado,codigoVuelo);
				    	printf("Nuevo codigo del vuelo: %s",codigoVuelo);
				    	break;
				}
					mostrarMenu2();
					utn_getNumero(&opcionMenu,"Ingrese la opción: \n","Reingrese la opcion: \n",1,5,3);
				}
			}
			retorno = 0;
		}
	}
    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int index, id;
	char respuesta[3];
	if(pArrayListPassenger != NULL){
		int len = ll_len(pArrayListPassenger);
		if(len > 0){
			Passenger* pPasajeroBuscado;
			Passengers_getAllList(pArrayListPassenger);
			utn_getNumero(&id,"Ingrese el id del pasajero a buscar: \n","Reingrese el id del pasajero a buscar: \n",1, 100000, 3);
			index = Passenger_searchById(pArrayListPassenger,id);
			if(index >= 0){
				printf("Esta seguro que desea eliminar al pasajero?\n");
				utn_getNombre(respuesta,3,"Esta seguro que desea eliminar al pasajero? [si/no] \n","Esta seguro que desea eliminar al pasajero? [si/no]\n",3);
				if(strcmp(respuesta,"Si")==0){
					ll_remove(pArrayListPassenger,index);
					Passenger_delete(pPasajeroBuscado);
					retorno = 0;
				}
			}
		}
	}

    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int i,retorno = -1;
	Passenger* pasajeroBuscado;
	if(pArrayListPassenger != NULL){
		for(i = 0; i <= ll_len(pArrayListPassenger); i++){
			pasajeroBuscado = ll_get(pArrayListPassenger,i);
			if(pasajeroBuscado !=NULL)
			Passenger_getAllInfo(pasajeroBuscado);
			retorno =0;
		}
	}
    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	if(pArrayListPassenger != NULL){
  //falta desarrollar
		retorno = 0;
	}

    return retorno;
}

/** \brief Guarda los datos en formato CSV
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *Si se puede salvar,retorna 0, sino -1
 */


int saveAsTextFormat(FILE* pFile, LinkedList* pArrayListPassenger){
	int retorno = -1;
	Passenger* pPasajero;
    int id;
    char nombre[50];
    char apellido[50];
    float precio;
    int tipoPasajero;
    char codigoVuelo[4];
    int i,len;
    int encabezado = 1;

	if(pFile != NULL && pArrayListPassenger !=NULL ){
		len = ll_len(pArrayListPassenger);

		for(i = 0; i < len; i++){
			pPasajero = ll_get(pArrayListPassenger,i);
			Passenger_getId(pPasajero,&id);
			Passenger_getNombre(pPasajero,nombre);
			Passenger_getApellido(pPasajero,apellido);
			Passenger_getTipoPasajero(pPasajero,&tipoPasajero);
			Passenger_getCodigoVuelo(pPasajero,codigoVuelo);
			Passenger_getPrecio(pPasajero,&precio);
			if(encabezado){
				fprintf(pFile,"%s,%s,%s,%s,%s,%s\n","Id","Nombre","Apellido","Precio","CodigoVuelo","TipoPasajero");
				encabezado = 0;
			}

			fprintf(pFile,"%d,%s,%s,%.2f,%s,%d\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero);
			retorno = 0;
		}
	}
	return retorno;
}


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE* pFile = fopen(path,"w"); //abro el archivo en modo escritura

	if(pFile != NULL && saveAsTextFormat(pFile,pArrayListPassenger) == 0){
		retorno = 0;
	}
	fclose(pFile); //cierro el archivo
	ll_clear(pArrayListPassenger); //vacio el array de pasajeros

    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    FILE* pFile;
    Passenger* pPasajero;
    int i, len;

    if(pArrayListPassenger != NULL && path != NULL){
    	pFile = fopen(path,"wb");
    	len = ll_len(pArrayListPassenger);
    	for(i = 0; i < len; i++){
    		pPasajero = ll_get(pArrayListPassenger,i);
    		fwrite(pPasajero,sizeof(Passenger),1,pFile);
    	}
    	fclose(pFile); //cierro el archivo
    	ll_clear(pArrayListPassenger); //vacio el array de pasajeros

         retorno = 0;
    }
    return retorno;
}



