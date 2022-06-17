/*
 * funciones.h
 *
 *  Created on: 17 jun. 2022
 *      Author: alida
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_



int calcularCostos(float km, float precio, float *precioTarjetaD, float *precioTarjetaC, float *precioBitcoin,float *precioPorKm);

int diferenciaDePrecios(float precioAerolineas, float precioLatam, float *diferenciaPrecio);

void mostrarMenuPrincipal();

void mostrarMenu2();

void mostrarResultados(float *precioTarjetaD, float *precioTarjetaC, float *precioBitcoin,float *precioPorKm);

void mostrarDiferenciaDePrecios(float *diferenciaPrecio);



#endif /* FUNCIONES_H_ */
