/*
 * input.c
 *
 *  Created on: 15 abr. 2022
 *      Author: Alí Ansidey
 */

#include "input.h"

int getFloat(char mensaje[],int reintentos, float minimo, float maximo, char mensajeError[], float *pNumeroIngresado){
int retorno = -1;
int retornoScan;
float numAuxF;

if(mensaje != NULL && mensajeError != NULL && minimo < maximo && pNumeroIngresado != NULL && reintentos >= 0){
    printf("%s", mensaje);
    retornoScan = scanf("%f", &numAuxF);


    do{
        if(retornoScan != 1 || numAuxF < minimo || numAuxF > maximo){
            printf("%s", mensajeError);
            retornoScan = scanf("%f", &numAuxF);
            reintentos--;

        }
        else{
            reintentos = 0;
            *pNumeroIngresado = numAuxF;
            retorno = 0;
        }
    }while(reintentos > 0);
}
return retorno;
}



int getInt(char mensaje[],int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroIngresado){
int retorno = -1;
int retornoScan;
int numAux;

if(mensaje != NULL && mensajeError != NULL && minimo < maximo && pNumeroIngresado != NULL && reintentos >= 0){
	printf("%s", mensaje);
	retornoScan = scanf("%d", &numAux);
	printf("\n%d",retornoScan);

    do{
        if(retornoScan != 1 || numAux < minimo || numAux > maximo){
            printf("%s", mensajeError);
            retornoScan = scanf("%d", &numAux);
            reintentos--;

        }
        else{
            reintentos = 0;
            *pNumeroIngresado = numAux;
            retorno = 0;
        }

    }while (reintentos > 0);
}
return retorno;
}


int getChar(char mensaje[], char mensajeError[], char *pCharIngresado, int reintentos){

int retorno = -1;
int retornoScan;
char charAux;
char maximo = 'z';
char minimo = 'a';

if(mensaje != NULL && mensajeError != NULL  && pCharIngresado != NULL && reintentos >= 0){
    printf("%s", mensaje);
    fflush(stdin);
    retornoScan = scanf("%c", &charAux);
    charAux = tolower(charAux);

    do{
        if(retornoScan != 1 || charAux < minimo || charAux > maximo){
            printf("%s", mensajeError);
            fflush(stdin);
            retornoScan = scanf("%c", &charAux);
            charAux = tolower(charAux);
            reintentos--;
        }
        else{
            reintentos = 0;
            *pCharIngresado = charAux;
            retorno = 0;
        }
    }while(reintentos >0);
}
return retorno;
}

int calcularCostos(float km, float precio, float *precioTarjetaD, float *precioTarjetaC, float *precioBitcoin,float *precioPorKm)
{
	int retorno = -1;
	float porcentajeDescuento = 0.10;
	float porcentajeInteres = 0.25;
	float bitcoin = 4606954.55;
	float precCDescuento, precCInteres, precBit, precPKm;

	if(km > 0 && precio >= 0){
		precCDescuento = precio - (precio * porcentajeDescuento);
		 *precioTarjetaD = precCDescuento;

		 precCInteres = precio + (precio * porcentajeInteres);
		 *precioTarjetaC = precCInteres;

		 precBit = precio/bitcoin;
		 *precioBitcoin =  precBit;

		 precPKm = precio / km;
		 *precioPorKm = precPKm;

		 retorno = 0;

	}
return retorno;
}

int diferenciaDePrecios(float precioAerolineas, float precioLatam, float *diferenciaPrecio){
	int retorno = -1;
	if(precioAerolineas >= 0 && precioLatam >= 0){
		*diferenciaPrecio = precioLatam - precioAerolineas;
		if(*diferenciaPrecio < 0){
			*diferenciaPrecio = *diferenciaPrecio*-1;
		}
		retorno = 0;
	}
	return retorno;
}




void mostrarMenuPrincipal(){
    printf("\n 1. Ingresar Kilómetros: [km=x]");
    printf("\n 2. Ingresar Precio de Vuelos: [Aerolíneas=y, Latam=z]");
    printf("\n 3. Calcular todos los costos: ");
    printf("\n 4. Informar Resultados: ");
    printf("\n 5. Carga forzada de datos  ");
    printf("\n 6. Salir");
    return;

}

void mostrarMenu2(){
 printf("\n Ingresar Precio de Vuelos: [Aerolíneas=y, Latam=z]");
 printf("\n - Precio vuelo Aerolíneas:");
 printf("\n - Precio vuelo Latam: \n");
}

void mostrarResultados(float *precioTarjetaD, float *precioTarjetaC, float *precioBitcoin,float *precioPorKm){
	char porcentaje = '%';
	printf("\n Tarjeta de débito [descuento 10%c] $ %.2f",porcentaje, *precioTarjetaD);
	printf("\n Tarjeta de crédito [interés 25%c] $ %.2f",porcentaje, *precioTarjetaC);
	printf("\n Bitcoin [1BTC -> 4606954.55 Pesos Argentinos]: $ %.5f", *precioBitcoin);
	printf("\n Mostrar precio por km [precio unitario]:$ %.2f \n", *precioPorKm);
}


void mostrarDiferenciaDePrecios(float *diferenciaPrecio){

  printf("\n La diferencia de precio es: $ %.2f \n", *diferenciaPrecio);
  printf("########################################################### \n");

}
