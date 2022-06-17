/*
 * funciones.c
 *
 *  Created on: 17 jun. 2022
 *      Author: Alí Ansidey
 */

#include "funciones.h"

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

