#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"


int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    int opc1, opc2, opc3, opc4,opc5, opc6, opc7, opc8, opc9;

    LinkedList* listaPasajeros = ll_newLinkedList();

    mostrarMenu1();
    utn_getNumero(&option,"Ingrese su opción\n","Reingrese su opción\n",1,10,3);
    do{
        switch(option)
        {
            case 1:
            	//carga archivo csv formato texto
            	opc1 = controller_loadFromText("data.csv",listaPasajeros);
            	if(opc1 == 0){
            		puts("Datos cargados con exito\n");
            	}
            	else{
            		puts("No se cargaron los datos\n");
            	}

                break;
            case 2:
            	//carga del archivo csv en formato binario
            	opc2  =controller_loadFromBinary("data.csv",listaPasajeros);
            	if(opc2 == 0){
            		puts("Datos cargados con exito\n");
            	}
            	else{
            		puts("No se cargaron los datos\n");
            	}
            	break;
            case 3:
             	opc3 = controller_addPassenger(listaPasajeros);
            	if(opc3 == 0){
            		puts("Datos cargados con exito\n");
            	}
            	else{
            		puts("No se cargaron los datos\n");
            	}
             	break;
            case 4:
            	opc4 = controller_editPassenger(listaPasajeros);
            	if(opc4 == 0){
            		puts("Se modificaron los datos del pasajero con exito\n");
            	}
            	else{
            		puts("No se pudieron modificar los datos\n");
            	}
            	break;
            case 5:
            	opc5 = controller_removePassenger(listaPasajeros);
            	if(opc5 == 0){
            		puts("Se eliminó al pasajero con exito\n");
            	}
            	else{
            		puts("No se pudo eliminar al pasajero\n");
            	}
            	break;
            case 6:
            	opc6 = controller_ListPassenger(listaPasajeros);
            	if(opc6 == 0){
            		puts("Se listaron a los pasajeros con éxito\n");
            	}
            	else{
            		puts("No se pueden listar los pasajeros\n");
            	}
            	break;
            case 7:
            	opc7 = controller_sortPassenger(listaPasajeros);
            	if(opc7 == 0){
            		puts("Se ordenaron los pasajeros con éxito\n");
            	}
            	else{
            		puts("No se puede ordenar a los pasajeros\n");
            	}
            	break;
            case 8:
            	opc8 = controller_saveAsText("data3.csv",listaPasajeros);
            	if(opc8 == 0){
            		puts("Se guardó el archivo con exito\n");
            	}
            	else{
            		puts("No se pudo guardar el archivo\n");
            	}
            	break;
            case 9:
            	opc9 = controller_saveAsBinary("data3.csv",listaPasajeros);
            	if(opc9 == 0){
            		puts("Se guardó el archivo bin con exito\n");
            	}
            	else{
            		puts("No se pudo guardar el archivo bin\n");
            	}
            	break;
        }
        mostrarMenu1();
        utn_getNumero(&option,"Ingrese su opción\n","Reingrese su opción\n",1,10,3);
    }while(option != 10);

    printf("Ha salido del sistema\n");
    return 0;
}
