/*
 ============================================================================
 Name        : TP1.c
 Author      : Alí Ansidey
 Version     : 1.0
 División    : E
 Description : Trabajo práctico Taller de Programación 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define INGRESAR_NUM_UNO 1
#define INGRESAR_NUM_DOS 2
#define OPERACIONES 3
#define INFORMAR 4
#define SALIR 5


int main(void) {
	int numeroUno;
	int numeroDos;
	int suma;
	int resta;
	int multiplicacion;
	float division;
	float factorialUno;
	float factorialDos;
	int operacion;


	do{
		printf("\n Menú de opciones: \n");
		printf("1.Ingresar 1er operando (A=x)  \n");
		printf("2.Ingresar 2do operando (B=y) \n");
		printf("3.Calcular todas las operaciones \n");
		printf("4.Informar resultados \n");
		printf("5. Salir del programa \n");
		operacion = IngresarEntero("Escoja una operación: ");

		switch(operacion){
		case INGRESAR_NUM_UNO:
			numeroUno = IngresarEntero("Ingrese el primer número: \n");
			break;

		case INGRESAR_NUM_DOS:
			numeroDos = IngresarEntero("Ingrese el segundo número: \n");
			break;

		case OPERACIONES:
			suma = Sumar(numeroUno, numeroDos);
			resta = Restar(numeroUno, numeroDos);
			multiplicacion = Multiplicar(numeroUno, numeroDos);
			division = Dividir(numeroUno, numeroDos);
			factorialUno = Factorial(numeroUno);
			factorialDos = Factorial(numeroDos);
			break;

		case INFORMAR:
			printf("\n Los resultados de las operaciones son: \n");
			printf("El número ingresado fue: %d \n", numeroUno);
			printf("El número ingresado fue: %d \n", numeroDos);
			printf("El resultado de %d + %d es: %d \n",numeroUno, numeroDos, suma);
			printf("El resultado de %d - %d es: %d \n",numeroUno, numeroDos, resta);

				if(numeroDos == 0 && division == 0){
					printf("No es posible dividir por cero \n");
				}
				else{
					printf("El resultado de %d / %d es: %.2f \n",numeroUno, numeroDos, division);
				}

				printf("El resultado de %d * %d es: %d \n",numeroUno, numeroDos, multiplicacion);

				if(factorialUno != 0){
					printf("El factorial del número %d es: %.0f \n", numeroUno, factorialUno);
				}
				else{
					printf("No existe factorial del número %d  \n", numeroUno);
				}


				if(factorialDos != 0){
					printf("El factorial del número %d es: %.0f \n", numeroDos, factorialDos);
				}
				else{
					printf("No existe factorial del número %d \n", numeroDos);
				}

				break;

		}
	}while(operacion != SALIR);

	return 0;
}
