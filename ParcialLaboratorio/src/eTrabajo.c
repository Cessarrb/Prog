#include "eTrabajo.h"

int Menu()
{
    int opcion;

    printf("\n\t***************\n");
    printf("  \t*     MENU    *");
    printf("\n\t***************\n");
    printf("1. ALTA TRABAJO\n");
    printf("2. MODIFICAR TRABAJO\n");
    printf("3. BAJA TRABAJO \n");
    printf("4. LISTADO TRABAJO\n");
    printf("5. LISTADO SERVICIOS\n");
    printf("6. TOTAL SERVICIOS PRESTADOS\n");
    printf("7. LISTADO POR MARCA DE BICICLETA\n");
    printf("8. LISTADO DE SERVICIOS CON MAS TRABAJOS\n");
    printf("9. LISTADO DE SERVICIOS REALIZADOS A BICICLETAS\n");
    printf("10. CANTIDAD DE BICICLETAS ROJAS CON SERVICIO ELEIGO POR USUARIO\n");
    printf("11. SALIR\n");
    opcion=GetIntConRango("Elija una opcion: ", "Error", 1, 11);

    return opcion;
}

void InicializarTrabajo(eTrabajo listaT[], int tamT)
{
	int i;

	for(i=0;i<tamT;i++)
	{
		listaT[i].isEmpty = VACIO;
	}
}

void HardcodeoDatosTrabajos(eTrabajo listaT[], int tamT)
{
    int i;
    eTrabajo listaHard[]={{1, "Specialized", 26, 20000, {10,9,1818}, OCUPADO},{2, "Merida", 12, 20001, {24,2,1904}, OCUPADO},
    						{3, "Trek", 16, 20002,{6,4,2019}, OCUPADO},{4, "Scott", 22, 20003, {17,5,2019}, OCUPADO},{5, "Tons", 22, 20001, {15,5,2020}, OCUPADO}};

    for(i=0;i<tamT;i++)
    {
    	listaT[i]=listaHard[i];
    }
}

int BuscarLibre(eTrabajo listaT[], int tamT)
{
	int i;
	int index;
	index = -1;

	for(i=0;i<tamT;i++)
	{
		if(listaT[i].isEmpty==VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}

int BuscarTrabajoPorId(eTrabajo listaT[], int tamT, int id)
{
    int i;
    int rtn;

    rtn=-1;

    if (listaT!=NULL && tamT>0)
	{
		for (i=0;i<tamT;i++)
		{
			if (listaT[i].id==id && listaT[i].isEmpty==OCUPADO)
			{
				rtn = i;
				break;
			}
		}
	}

    return rtn;
}
