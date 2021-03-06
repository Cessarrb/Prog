#include "Nexo.h"

eTrabajo PedirDatos(eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, int idTrabajoIncremental)
{
	eTrabajo trabajo;

	printf("Numero de ID otorgado: %d\n", idTrabajoIncremental);
	MostrarBicicletas(listaB, tamB);
	trabajo.idBicicleta=GetIntConRango("Ingrese el ID de la bicicleta que desea darle un servicio: ", "Error", 25, 29);
	MostrarServicios(listaS, tamS);
	trabajo.idServicio=GetIntConRango("Ingrese el ID del servicio que desea: ", "Error", 20000, 20003);
	trabajo.fecha.dia=GetIntConRango("Ingrese el dia, del 1 al 31: ", "Error", 1, 31);
	trabajo.fecha.mes=GetIntConRango("Ingrese el mes, del 1 al 12: ", "Error", 1, 12);
	trabajo.fecha.anio=GetIntConRango("Ingrese el a?o, de 2021 a 2021: ", "Error", 2021, 2021);

	trabajo.isEmpty=OCUPADO;

	return trabajo;
}

int DarAltaTrabajo(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, int idTrabajoIncremental)
{
    int i;
    int rtn=0;

    i=BuscarLibre(listaT, tamT);

    if(i!=-1)
    {
    	 listaT[i] = PedirDatos(listaS, tamS, listaB, tamB, idTrabajoIncremental);
    	 listaT[i].id=idTrabajoIncremental;
    	 rtn=1;
    }

    return rtn;
}

int DarBajaTrabajo(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB)
{
    int id;
    int index;
    char respuesta;
    int rtn =0;
    int flag =0;

    if(MostrarTrabajos(listaT, tamT, listaS, tamS, listaB, tamB))
    {
    	flag=1;
    }

    if(flag)
    {
    	 id=GetInt("Ingrese el ID del trabajo que desea dar de baja: ", "Error");
    	 index=BuscarTrabajoPorId(listaT, tamT, id);
    	 while(index == -1)
		 {
			 printf("Error. ");
			 id=GetInt("Ingrese el ID del trabajo que desea dar de baja: ", "Error");
			 flag++;
			 if(flag==3)//Hago uso de la bandera como un contador para romper el while por varios intentos fallidos
			 {
				 printf("Supero el limite de intentos para ingresar un ID, se regresara al menu principal.\n");
				 break;
			 }
		 }
    	 if(flag!=3)
    	 {
    		 respuesta=GetChar("Esta seguro que desea dar de baja el trabajo? Ingrese [s] para continuar o [n] para cancelar: ", "Error");
    		 respuesta=tolower(respuesta);
			 if(respuesta=='s')
			 {
				 listaT[index].isEmpty=VACIO;
				 rtn=1;
			 }
    	 }
    }

    return rtn;
}

int ModificarTrabajo(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB)
{
	int id;
	char respuesta;
	int opcion;
	int flag=0;
	int rtn=0;
	int index;


	if(MostrarTrabajos(listaT, tamT, listaS, tamS, listaB, tamB))
	{
		flag=1;
	}

	if(flag)
	{

		id=GetInt("Ingrese el ID del trabajo que desea modificar: ", "Error");
		index=BuscarTrabajoPorId(listaT, tamT, id);
		while(index==-1)
		{
			printf("Error. ");
			id=GetInt("Ingrese el ID del trabajo que desea modificar: ", "Error");
			flag++;
			if(flag==3)//Hago uso de la bandera como un contador para romper el while por varios intentos fallidos
			{
				printf("Supero el limite de intentos para ingresar un ID, se regresara al menu principal.\n");
				break;
			}
		}
		if(flag!=3)
		{
			respuesta=GetChar("Esta seguro que desea modificar el trabajo? Ingrese [s] para continuar o [n] para cancelar: ", "Error");
			respuesta=tolower(respuesta);
			if(respuesta=='s')
			{
				printf("1-SERVICIO\n");
				printf("2-SALIR\n");
				opcion=GetIntConRango("Ingrese una opcion: ", "Error", 1, 2);
				switch(opcion)
				{
					case 1:
						MostrarServicios(listaS, tamS);
						listaT[index].idServicio=GetIntConRango("Ingrese el ID del nuevo servicio: ", "ERROR", 20000, 20003);
						rtn=1;
						break;
				}
			}
		}
	}

	return rtn;
}

int MostrarUnTrabajo(eTrabajo trabajo, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB)
{
	int rtn=0;
	char descripcionServicio[30];
	char marcaBicicleta[30];
	int indexServicio;
	int indexBicicleta;
	int rodado;
	char color[30];

	if(listaS != NULL && tamS >0)
	{
		indexServicio=BuscarServicioPorId(listaS, tamS, trabajo.idServicio);
		if(indexServicio!=-1)
		{
			strcpy(descripcionServicio, listaS[indexServicio].descripcion);
		}
		else
		{
			strcpy(descripcionServicio, "ERROR");
		}

		indexBicicleta=BuscarBiciPorId(listaB, tamB, trabajo.idBicicleta);
		if(indexBicicleta!=-1)
		{
			strcpy(marcaBicicleta, listaB[indexBicicleta].marca);
			strcpy(color, listaB[indexBicicleta].color);
			rodado=listaB[indexBicicleta].rodadoBicicleta;

		}
		printf("%2d %15s %10d %10s %10s %8d-%d-%d\n", trabajo.id, marcaBicicleta, rodado, color, descripcionServicio, trabajo.fecha.dia,
														trabajo.fecha.mes, trabajo.fecha.anio);
		rtn=1;
	}

	return rtn;
}

int MostrarTrabajos(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB)
{
	int i;
	int rtn=0;

	if (listaT != NULL && tamT>0)
	{
		OrdenarPorFecha(listaT, tamT, listaB, tamB);
		for(i=0;i<tamT;i++)
		{
			if(listaT[i].isEmpty == OCUPADO)
			{
				if(rtn==0) //uso la variable rtn para mostrar el encabezado
				{
					printf("%2s %15s %10s %10s %10s %15s\n", "ID", "MARCA", "RODADO", "COLOR", "SERVICIO", "FECHA");
				}
				MostrarUnTrabajo(listaT[i], listaS, tamS, listaB, tamB);
				rtn=1;
			}
		}
	}

	return rtn;
}

void MostrarUnServicioPrestado(eAuxiliar listaAux)
{
	printf("%8s %7d %18.2f\n", listaAux.descripcion, listaAux.contador, listaAux.acumulador);

}

int MostrarServiciosPrestados(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS)
{
	eAuxiliar listaAux[tamS];
	int i;
	int j;
	int rtn=0;
	InicializarAxuliar(listaAux, listaT, tamT, listaS, tamS);
	ContadorAcumuladorAxuliar(listaAux, listaT, tamT, listaS, tamS);

	if(listaT !=NULL && listaS != NULL && tamT>0)
	{
		for(i=0;i<tamS;i++)
		{
			for(j=0;j<tamT;j++)
			{
				if(listaAux[i].isEmpty==OCUPADO)
				{
					if(rtn==0)
					{
						printf("%8s %10s %18s\n","SERVICIO", "CANTIDAD", "TOTAL PESOS");
					}
					MostrarUnServicioPrestado(listaAux[i]);
					rtn=1;
					break;
				}
			}
		}
	}

	return rtn;
}


int InicializarAxuliar(eAuxiliar auxiliar[], eTrabajo listaT[], int tamT, eServicio listaS[], int tamS)
{
	int rtn=0;
    int i;

    for(i=0;i<tamS;i++)
    {
        auxiliar[i].id=listaS[i].id;
        strcpy(auxiliar[i].descripcion, listaS[i].descripcion);
        auxiliar[i].contador=0;
        auxiliar[i].acumulador=0;
        auxiliar[i].isEmpty=VACIO;
        rtn=1;
    }

    return rtn;
}

int ContadorAcumuladorAxuliar(eAuxiliar auxiliar[], eTrabajo listaT[], int tamT, eServicio listaS[], int tamS)
{

	int rtn=0;
    int i;
    int j;

    if(auxiliar != NULL && listaT != NULL && tamT>0 && listaS != NULL && tamS>0)
    {
		for(i=0;i<tamT;i++)
		{
			for(j=0;j<tamS;j++)
			{
				if(auxiliar[j].id==listaT[i].idServicio)
				{
					auxiliar[j].contador++;
					auxiliar[j].acumulador+=listaS[j].precio;
					auxiliar[j].isEmpty=OCUPADO;
				}
			}
		}
    }

    return rtn;
}


void OrdenarPorFecha(eTrabajo listaT[], int tamT, eBicicleta listaB[], int tamB)
{
	int i;
	int j;
	int indexBicicleta;
	int indexBicicletaDos;
	eTrabajo auxiliar;

	if(listaT != NULL && tamT>0 && listaB != NULL && tamB>0)
	{
		if (listaT != NULL && tamT>0)
		{
			for(i=0;i<tamT-1;i++)
			{
				indexBicicleta = BuscarBiciPorId(listaB, tamB, listaB[i].idBicicleta);
				for(j=i+1;j<tamT;j++)
				{
					indexBicicletaDos = BuscarBiciPorId(listaB, tamB, listaB[j].idBicicleta);
					if(listaT[i].fecha.anio>listaT[j].fecha.anio)
					{
						auxiliar=listaT[i];
						listaT[i]=listaT[j];
						listaT[j]=auxiliar;
					}
					if(listaT[i].fecha.anio==listaT[j].fecha.anio && strcmp(listaB[indexBicicleta].marca, listaB[indexBicicletaDos].marca)>0)
					{
						auxiliar=listaT[i];
						listaT[i]=listaT[j];
						listaT[j]=auxiliar;
					}
				}
			}
		}
	}
}

int OrdenarPorMarca(eTrabajo listaT[], int tamT, eBicicleta listaB[], int tamB)
{
	int rtn=0;
	int i;
	int j;
	int indexBicicleta;
	int indexBicicletaDos;
	eTrabajo auxTrabajo;

	if(listaT != NULL && listaB != NULL && tamB>0)
	{
		for (i=0;i<tamT-1;i++)
		{
			indexBicicleta = BuscarBiciPorId(listaB, tamB, listaB[i].idBicicleta);
			for(j=i+1;j<tamT;j++)
			{
				indexBicicletaDos = BuscarBiciPorId(listaB, tamB, listaB[j].idBicicleta);
				if (strcmp(listaB[indexBicicleta].marca ,listaB[indexBicicletaDos].marca)>0)
				{
					auxTrabajo=listaT[i];
					listaT[i]=listaT[j];
					listaT[j]=auxTrabajo;
					rtn=1;
				}
			}
		}
	}

	return rtn;
}

int ServicioConMasTrabajosRealizado(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS)
{
	eAuxiliar listaAux[tamS];
	int rtn=0;
	int i=0;
	int maxServicio;
	int flag=0;
	int indexServicio;

	InicializarAxuliar(listaAux, listaT, tamT, listaS, tamS);
	ContadorAcumuladorAxuliar(listaAux, listaT, tamT, listaS, tamS);

	for(i=0;i<tamS;i++)
	{
		if(listaAux[i].isEmpty==OCUPADO)
		{
			if(flag==0 || listaAux[i].contador>maxServicio)
			{
				maxServicio=listaAux[i].contador;
				flag=1;
			}
		}
	}

	for(i=0;i<tamS;i++)
	{
		if(listaAux[i].isEmpty==OCUPADO)
		{
			if(listaAux[i].contador==maxServicio)
			{
				indexServicio=BuscarServicioPorId(listaS, tamS, listaAux[i].id);
				printf("El servicio con mayor cantidad de trabajos es: %s con %d productos\n", listaS[indexServicio].descripcion, maxServicio);
				rtn=1;
			}
		}
	}
	return rtn;
}

int DatosBicicleta(eTrabajo trabajo, eBicicleta listaB[], int tamB)
{
	int rtn=0;
	int indexBicicleta;
	int id;
	char marcaBicicleta[30];
	int rodado;
	char color[30];

		indexBicicleta=BuscarBiciPorId(listaB, tamB, trabajo.idBicicleta);
		if(indexBicicleta!=-1)
		{
			id=listaB[indexBicicleta].idBicicleta;
			strcpy(marcaBicicleta, listaB[indexBicicleta].marca);
			strcpy(color, listaB[indexBicicleta].color);
			rodado=listaB[indexBicicleta].rodadoBicicleta;

		}
		printf("%2d %15s %10d %10s\n", id, marcaBicicleta, rodado, color);
		rtn=1;

	return rtn;
}

int MostrarDatosBicleta(eTrabajo listaT[], int tamT, eBicicleta listaB[], int tamB)
{
	int i;
	int rtn=0;

	if (listaT != NULL && tamT>0)
	{
		for(i=0;i<tamT;i++)
		{
			if(listaT[i].isEmpty == OCUPADO)
			{
				DatosBicicleta(listaT[i], listaB, tamB);
				rtn=1;
			}
		}
	}

	return rtn;
}

void ListaBicicletasPorServicio(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB)
{
    int i;
    int j;
    int indexBicicleta;

    for(i=0;i<tamS;i++)
    {
		printf("---------------------------------------------\n");
		printf("Servido de %s | Precio: %.2f\n", listaS[i].descripcion, listaS[i].precio);
		printf("%2s %15s %10s %15s\n", "ID", "MARCA", "RODADO", "COLOR");
		printf("---------------------------------------------\n");
        for(j=0;j<tamT;j++)
        {
            if(listaT[j].idServicio==listaS[i].id)
            {
            	indexBicicleta=BuscarBiciPorId(listaB, tamB, listaT[j].idBicicleta);
            	printf("%2d %15s %10d %15s\n", listaB[indexBicicleta].idBicicleta, listaB[indexBicicleta].marca,
            									listaB[indexBicicleta].rodadoBicicleta, listaB[indexBicicleta].color);
            }
        }
    }
}
