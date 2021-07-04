#include "Nexo.h"
#define TS 4
#define TT 5
#define TB 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_AUX 50
#define VACIO -1
#define OCUPADO 0

int main(void)
{
	setbuf(stdout, NULL);

	int idTrabajoIncremental = 1;
	int opcion;

	//Estructuras
	eTrabajo listaT[TT];
	eServicio listaS[TS];
	eBicicleta listaB[TB];

	//Hardcodeo
	//HardcodeoDatosTrabajos(listaT, TT);
	HardcodeoDatosBicicleta(listaB, TB);
	HardcodeoDatosServicios(listaS, TS);
	InicializarTrabajo(listaT, TT);

	do
	{
		opcion=Menu();
		switch(opcion)
		{
			case 1:
				if(DarAltaTrabajo(listaT, TT, listaS, TS, listaB, TB, idTrabajoIncremental))
				{
					idTrabajoIncremental+=1;
					printf("Se dio de alta!");
				}
				else
				{
					printf("No hay espacio.");
				}

				break;
			case 2:
				if(ModificarTrabajo(listaT, TT, listaS, TS, listaB, TB))
				{
					printf("Dato modificado con exito!");
				}
				else
				{
					printf("No hay datos cargados.\n");
				}
				break;
			case 3:
				if(DarBajaTrabajo(listaT, TT, listaS, TS, listaB, TB))
				{
					printf("Se dio de baja!");
				}
				else
				{
					printf("No hay datos cargados.\n");
				}
				break;
			case 4:
				if(!MostrarTrabajos(listaT, TT, listaS, TS, listaB, TB))
				{
					printf("No hay datos cargados.\n");
				}

				break;
			case 5:
				MostrarServicios(listaS, TS);
				break;
			case 6:
				if(!MostrarServiciosPrestados(listaT, TT, listaS, TS))
				{
					printf("No hay datos cargados.\n");
				}
				break;
			case 7:
				if(!OrdenarPorMarca(listaT, TT, listaB, TB))
				{
					printf("Ocurrio un error.\n");
				}
				break;
			case 8:
				if(!ServicioConMasTrabajosRealizado(listaT, TT, listaS, TS))
				{
					printf("No hay datos cargados.\n");
				}
				break;
			case 9:
				ListaBicicletasPorServicio(listaT, TT, listaS, TS, listaB, TB);
				break;
			case 10:

				break;
		}
	}while(opcion!=11);


	return EXIT_SUCCESS;
}
