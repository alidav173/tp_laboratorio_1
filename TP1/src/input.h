/*
 * input.h
 *
 *  Created on: 15 abr. 2022
 *      Author: alida
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>


int getFloat(char mensaje[],int reintentos, float minimo, float maximo, char mensajeError[], float *pNumeroIngresado);

int getInt(char mensaje[],int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroIngresado);

int getChar(char mensaje[], char mensajeError[], char *pCharIngresado, int reintentos);

int calcularCostos(float km, float precio, float *precioTarjetaD, float *precioTarjetaC, float *precioBitcoin,float *precioPorKm);

int diferenciaDePrecios(float precioAerolineas, float precioLatam, float *diferenciaPrecio);

void mostrarMenuPrincipal();

void mostrarMenu2();

void mostrarResultados(float *precioTarjetaD, float *precioTarjetaC, float *precioBitcoin,float *precioPorKm);

void mostrarDiferenciaDePrecios(float *diferenciaPrecio);

#endif /* INPUT_H_ */
