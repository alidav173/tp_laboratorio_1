/*
 * funciones.c
 *
 *  Created on: 23 sep. 2021
 *      Author: Alí Ansidey
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*Pide el ingreso de un número por teclado. Devuelve un entero*/
int IngresarEntero(char mensaje[])
{
	setbuf(stdout, NULL);
	int numeroIngresado;
	printf("%s", mensaje);
	scanf("%d", &numeroIngresado);

	return numeroIngresado;
}

/*Pide el ingreso de un número por teclado. Devuelve un flotante*/
float IngresarFlotante(char mensaje[])
{
	setbuf(stdout, NULL);
	float numeroIngresado;
	printf("%s", mensaje);
	scanf("%f", &numeroIngresado);

	return numeroIngresado;
}

/*Suma dos valores pasados por parametros. Devuelve un entero*/
int Sumar(int num1, int num2){
	int suma;
	suma = num1 + num2;
	return suma;
}

/*Resta dos valores pasados por parametros. Devuelve un entero*/
int Restar(int num1, int num2){
	int resta;
	resta = num1 - num2;
	return resta;
}


/*Multiplica dos valores pasados por parametros. Devuelve un entero*/
int Multiplicar(int num1, int num2){
	int multiplicacion;
	multiplicacion = num1 * num2;
	return multiplicacion;
}


/*Divide dos valores pasados por parametros. Devuelve un float*/
float Dividir(int num1, int num2){
	float division;
	if(num2 == 0){
		division = 0;
	}
	else{
		division = (float) num1 / num2;
	}
	return division;

}

/*Calcula el factorial de un número pasado por parametros. Devuelve un entero*/
float Factorial(int num1) {
	float factorial = 1;
	int i;
	if(num1 > 0){
		for(i = 1; i <= num1 ; i++){
			factorial = factorial * i;

	}
	}

	else if(num1 == 0){
		factorial = 1;
	}

	else{
		factorial = 0;
	}

	return factorial;

}

