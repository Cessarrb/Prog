/*
 ============================================================================
 Name        : Parcial2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "LinkedList.h"
#include "Controller.h"
#include "Input.h"


int main(void) {

	LinkedList* listaVuelos = ll_newLinkedList();
	LinkedList* listaPilotos = ll_newLinkedList();
	int opcion;

	setbuf(stdout, NULL);


	do{
		opcion=Vuelo_Menu();

		switch(opcion)
		{
			case 1:
				if(controller_cargaDesdeTextoPilotos("Pilotos.csv", listaPilotos))
				{
					printf("DATOS CARGADOS!\n");
				}
				else
				{
					printf("Hubo un problema.");
				}
				break;
			case 2:
				if(controller_cargaDesdeTextoVuelos("Vuelos.csv", listaVuelos))
				{
					printf("DATOS CARGADOS!\n");
				}
				else
				{
					printf("Hubo un problema.");
				}
				break;
			case 3:
				if(controller_imprimirVuelos(listaVuelos, listaPilotos))
				{
					printf("DATOS CARGADOS!\n");
				}
				break;
			case 4:
				break;
			case 5:
				break;
		}
	}while(opcion!=5);

	return EXIT_SUCCESS;
}
