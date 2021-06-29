#include "eVuelo.h"

int Vuelo_Menu()
{
	int opcion;

	printf("\n\t***************\n");
	printf("  \t*     MENU    *");
	printf("\n\t***************\n");
	printf("1. Cargar archivos pilotos\n");
	printf("2. Cargar archivos vuelos\n");
	printf("3. Imprimir vuelos\n");
	printf("4. Cantidad pasajeros\n");
	printf("5. Cantidad pasajeros a China\n");
	printf("6. Salir\n");

	if(!GetIntConRango(&opcion, "Ingrese una opcion: ", "Error", 1, 10))
	{
		printf("Demasiados intentos incorrectos, se cerrara el programa.");
		opcion=10;
	}
	return opcion;
}

eVuelo* vuelo_new()
{
	eVuelo* pVuelo;

	pVuelo = (eVuelo*) calloc(sizeof(eVuelo), 1);

	return pVuelo;
}

eVuelo* vuelo_newParametros(char* id, char* idAvion, char* idPiloto, char* dia, char* mes, char* anio, char* destino,  char* cantPasajeros, char* horaDespegue, char* horaLlegada)
{
	eVuelo* pVuelo;

	pVuelo = vuelo_new();

	if(id != NULL && destino != NULL && horaDespegue != NULL && horaLlegada != NULL)
	{
		vuelo_setId(pVuelo, atoi(id));
		vuelo_setIdAvion(pVuelo, atoi(idAvion));
		vuelo_setIdPiloto(pVuelo, atoi(idPiloto));
		vuelo_setDestino(pVuelo, destino);
		vuelo_setFecha(pVuelo, atoi(dia), atoi(mes), atoi(anio));
		vuelo_setCantPasajeros(pVuelo, atoi(cantPasajeros));
		vuelo_setHoraDespegue(pVuelo, atoi(horaDespegue));
		vuelo_setHoraLlegada(pVuelo, atoi(horaLlegada));
	}

	return pVuelo;
}

int vuelo_setId(eVuelo* this, int id)
{
	int rtn=0;

	if(this != NULL && id>0)
	{
		this->idVuelo=id;
		rtn=1;
	}

	return rtn;
}
int vuelo_getId(eVuelo* this, int* id)
{
	int rtn=0;


	if(this != NULL && id != NULL)
	{
		*id=this->idVuelo;
		rtn=1;
	}

	return rtn;
}

int vuelo_setIdAvion(eVuelo* this, int id)
{
	int rtn=0;

	if(this != NULL && id>0)
	{
		this->idAvion=id;
		rtn=1;
	}

	return rtn;
}
int vuelo_getIdAvion(eVuelo* this, int* id)
{
	int rtn=0;


	if(this != NULL && id != NULL)
	{
		*id=this->idAvion;
		rtn=1;
	}

	return rtn;
}

int vuelo_setIdPiloto(eVuelo* this, int id)
{
	int rtn=0;

	if(this != NULL && id>0)
	{
		this->idPiloto=id;
		rtn=1;
	}

	return rtn;
}
int vuelo_getIdPiloto(eVuelo* this, int* id)
{
	int rtn=0;

	if(this != NULL && id != NULL)
	{
		*id=this->idPiloto;
		rtn=1;
	}

	return rtn;
}

int vuelo_setDestino(eVuelo* this, char* destino)
{
	int rtn=0;

	if(this != NULL && strlen(destino)>0)
	{
		strcpy(this->destino, destino);
		rtn=1;
	}

	return rtn;
}
int vuelo_getDestino(eVuelo* this, char* destino)
{
	int rtn=0;

	if(this != NULL && strlen(destino)>0)
	{
		strcpy(destino, this->destino);
		rtn=1;
	}

	return rtn;
}

int vuelo_setCantPasajeros(eVuelo* this, int cantPasajeros)
{
	int rtn=0;

	if(this != NULL && cantPasajeros>0 && cantPasajeros <100)
	{
		this->cantPasajeros=cantPasajeros;
		rtn=1;
	}

	return rtn;
}

int vuelo_getCantPasajeros(eVuelo* this, int* cantPasajeros)
{
	int rtn=0;

	if(this != NULL && cantPasajeros != NULL)
	{
		*cantPasajeros=this->cantPasajeros;
		rtn=1;
	}

	return rtn;
}

int vuelo_setHoraDespegue(eVuelo* this, int horaDespegue)
{
	int rtn=0;

	if(this != NULL && horaDespegue>0 && horaDespegue<24)
	{
		this->horaDespegue=horaDespegue;
		rtn=1;
	}

	return rtn;
}

int vuelo_getHoraDespegue(eVuelo* this, int* horaDespegue)
{
	int rtn=0;

	if(this != NULL && horaDespegue != NULL)
	{
		*horaDespegue=this->horaDespegue;
		rtn=1;
	}

	return rtn;
}

int vuelo_setHoraLlegada(eVuelo* this, int horaLlegada)
{
	int rtn=0;

	if(this != NULL && horaLlegada>0 && horaLlegada<24)
	{
		this->horaLlegada=horaLlegada;
		rtn=1;
	}

	return rtn;
}

int vuelo_getHoraLlegada(eVuelo* this, int* horaLlegada)
{
	int rtn=0;

	if(this != NULL && horaLlegada != NULL)
	{
		*horaLlegada=this->horaLlegada;
		rtn=1;
	}

	return rtn;
}

int vuelo_setFecha(eVuelo* this, int dia, int mes, int anio)
{
	int rtn=0;

	if(this != NULL && dia>0 && dia<31 && mes>0 && mes < 12 && anio > 2000 && anio < 2021)
	{
		this->fecha.dia=dia;
		this->fecha.mes=mes;
		this->fecha.anio=anio;
		rtn=1;
	}

	return rtn;
}

int vuelo_getFecha(eVuelo* this, int* dia, int* mes, int* anio)
{
	int rtn=0;

	if(this != NULL && dia != NULL && mes != NULL && anio != NULL)
	{
		*dia=this->fecha.dia;
		*mes=this->fecha.mes;
		*anio=this->fecha.anio;
		rtn=1;
	}

	return rtn;
}

/*int vuelo_printvuelo(LinkedList* pArrayListvuelo, int index)
{
	int i=0;
	int rtn;
	eVuelo* pVuelo;

	if(pArrayListvuelo!=NULL && index>=0)
	{
		if(i==0)
		{
			printf("##==============================================##\n");
			printf("||%4s || %15s || %7s || %7s ||\n", "ID", "NOMBRE", "HORAS", "SUELDO");
			printf("##==============================================##\n");
			i++;
		}
		pvuelo = (vuelo*) ll_get(pArrayListvuelo, index);

		printf("||%4d || %15s || %7d || %7d ||\n", pVuelo->id, pVuelo->nombre, pVuelo->horasTrabajadas, pVuelo->sueldo);
		rtn=1;
		if(rtn==1)
		{
			printf("##==============================================##\n");
		}
	}

    return rtn;
}*/

int vuelo_printvuelos(LinkedList* pListaVuelos, LinkedList* pListaPilotos)
{
	eVuelo* pVuelo;
	ePiloto* pPiloto;
	int i;
	int j;
	int idAvion;
	int idVueloPiloto;
	char nombre[128];
	int idPiloto;
	int cantPasajeros;
	char destino[128];
	int horaDespegue;
	int horaLlegada;
	int dia;
	int mes;
	int anio;
	int rtn=0;

	if(pListaVuelos != NULL)
	{
		for(i=0;i<ll_len(pListaVuelos);i++)
		{
			pVuelo = (eVuelo*)ll_get(pListaVuelos, i);
			vuelo_getId(pVuelo, &idVueloPiloto);
			for(j=0;j<ll_len(pListaPilotos);j++)
			{
				pPiloto = (ePiloto*)ll_get(pListaPilotos, j);
				piloto_getId(pPiloto, &idPiloto);

				if(idVueloPiloto == idPiloto)
				{
					piloto_getNombre(pPiloto, nombre);
				}
			}

			if(i==0)
			{
				printf("##=====================================================================================================================================##\n");
				printf("|| %8s || %10s || %15s || %15s || %15s || %15s || %12s || %12s ||\n", "ID VUELO", "ID AVION", "NOMBRE PILOTO", "FECHA", "DESTINO", "CANT.PASAJEROS", "HORA DESPEGUE", "HORA LLEGADA");
				printf("##=====================================================================================================================================##\n");
			}
			if(pVuelo != NULL && pVuelo != 0)
			{
				vuelo_getIdAvion(pVuelo, &idAvion);
				vuelo_getDestino(pVuelo, destino);
				vuelo_getHoraDespegue(pVuelo, &horaDespegue);
				vuelo_getHoraLlegada(pVuelo, &horaLlegada);
				vuelo_getCantPasajeros(pVuelo, &cantPasajeros);
				vuelo_getFecha(pVuelo, &dia, &mes, &anio);
			}
			printf("|| %8d || %10d || %15s || %7d/%d/%d || %15s || %15d || %13d || %12d ||\n", idVueloPiloto, idAvion, nombre, dia, mes, anio, destino, cantPasajeros, horaDespegue, horaLlegada);
			rtn=1;
		}
		if(rtn==1)
		{
			printf("##=====================================================================================================================================##\n");
		}
	}

	return rtn;
}


