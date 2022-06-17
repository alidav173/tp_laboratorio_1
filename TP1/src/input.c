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

