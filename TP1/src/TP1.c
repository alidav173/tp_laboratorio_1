/*
 ============================================================================
 Name        : TP1_LABORATORIO.c
 Author      : Alí Ansidey
 Version     :1.0.1
 Copyright   : Your copyright notice
 Description : TP1 LABORATORIO PROGRAMACION 1
 ============================================================================
 */

#include <stdio.h>
#include "input.h"
#include "funciones.h"
#include <limits.h>
#define SALIDA 6
#define ERROR -1
#define AEROLINEAS 'y'
#define LATAM 'z'

int main()
{
   setbuf (stdout, NULL);
   int opcionELegida, validacion, contadorErrores;
   float kilometraje, precioAerolineas, precioLatam, precioTarjetaDlatam,precioTarjetaDAero, precioTarjetaCLatam, precioTarjetaCAero, precioBitcoinLatam, precioBitcoinAero, diferenciaPrecio, precioPorKmAero,precioPorKmLatam ;
   char opcionMenu2;

   mostrarMenuPrincipal();

   validacion = getInt("\n Ingrese la opción: ",3, 1, 6, "\n Reingrese la opcion nuevamente:\n", &opcionELegida);
   while(validacion!=ERROR && opcionELegida!=SALIDA){
      switch(opcionELegida){
       case 1:
       validacion = getFloat("\n Ingrese el kilometraje: ",3, 1, INT_MAX, "\n Reingrese el kilometraje: \n", &kilometraje);
       break;

       case 2:
       mostrarMenu2();
       validacion = getChar("\n Ingrese la aerolinea: [y - aerolineas / z- latam]", "\n Reingrese la aerolinea:[y - aerolineas / z- latam] \n", &opcionMenu2, 3);
       while(opcionMenu2 !=AEROLINEAS && opcionMenu2 != LATAM){
    	   getChar("\n Ingrese la aerolinea: [y - aerolineas / z- latam]", "\n Reingrese la aerolinea: [y - aerolineas / z- latam]\n", &opcionMenu2, 3);
       }

       if(opcionMenu2 == AEROLINEAS){
    	   getFloat("\n Ingrese el precio de Aerolineas: ",3, 0, INT_MAX, "\n Ingrese el precio Aerolineas:", &precioAerolineas);

       }
       if(opcionMenu2 == LATAM){
    	   getFloat("\n Ingrese el precio de Latam: ",3, 0, INT_MAX, "\n Ingrese el precio Latam:", &precioLatam);

       }
       break;

       case 3:
    	   contadorErrores = 0;
    	   validacion = calcularCostos(kilometraje, precioAerolineas, &precioTarjetaDAero, &precioTarjetaCAero, &precioBitcoinAero, &precioPorKmAero);
    	   contadorErrores +=validacion;
    	   validacion = calcularCostos(kilometraje, precioLatam, &precioTarjetaDlatam, &precioTarjetaCLatam, &precioBitcoinLatam, &precioPorKmLatam);
    	   contadorErrores +=validacion;
    	   validacion = diferenciaDePrecios(precioAerolineas, precioLatam, &diferenciaPrecio);
    	   contadorErrores +=validacion;
    	   if(contadorErrores == 0){
    		   printf("\n Se han realizado los calculos con éxito");
    	   }
    	   else
    		   printf("\n No se han realizado los calculos");
       break;

       case 4:
    	   if(contadorErrores ==0){
    	       printf("\n Km ingresados: %.2f",kilometraje);
    	       printf("\n Precio Aerolineas: %.2f",precioAerolineas);
    	       mostrarResultados(&precioTarjetaDAero, &precioTarjetaCAero, &precioBitcoinAero,&precioPorKmAero);
    	       printf("\n Precio Latam: %.2f",precioLatam);
    	       mostrarResultados(&precioTarjetaDlatam, &precioTarjetaCLatam, &precioBitcoinLatam,&precioPorKmLatam);
    	       mostrarDiferenciaDePrecios(&diferenciaPrecio);
    	   }
    	   else{
    		   printf("\n No se ingresaron los datos para hacer los calculos");
    	   }
    	   break;

       case 5:
       kilometraje = 7090;
       precioAerolineas = 162965;
       precioLatam = 159339;

       calcularCostos(kilometraje, precioAerolineas, &precioTarjetaDAero, &precioTarjetaCAero, &precioBitcoinAero, &precioPorKmAero);
       calcularCostos(kilometraje, precioLatam, &precioTarjetaDlatam, &precioTarjetaCLatam, &precioBitcoinLatam, &precioPorKmLatam);
       diferenciaDePrecios(precioAerolineas, precioLatam, &diferenciaPrecio);
       printf("\n Precio Aerolineas: %.2f",precioAerolineas);
       mostrarResultados(&precioTarjetaDAero, &precioTarjetaCAero, &precioBitcoinAero,&precioPorKmAero);
       printf("\n Precio Latam: %.2f",precioLatam);
       mostrarResultados(&precioTarjetaDlatam, &precioTarjetaCLatam, &precioBitcoinLatam,&precioPorKmLatam);
       mostrarDiferenciaDePrecios(&diferenciaPrecio);
       break;


   }
   mostrarMenuPrincipal();
   fflush(stdin);
   validacion = getInt("\n Ingrese la opción: ",3, 1, 6, "\n Reingrese la opcion nuevamente:", &opcionELegida);
   }
    printf("\n Ha salido del sistema");
    return 0;
}
