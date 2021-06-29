#include "Parser.h"


int parser_vuelos(FILE* pFile, LinkedList* pListaVuelo)
{
	eVuelo* pVuelo;

	int rtn=0;
	char idVuelo[50];
	char idAvion[50];
	char idPiloto[50];
	char fecha[50];
	char fechaDia[50];
	char fechaMes[50];
	char fechaAnio[50];
	char destino[50];
	char cantPasajeros[50];
	char horaDespegue[50];
	char horaLlegada[50];

	if(pFile != NULL && pListaVuelo != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idVuelo, idAvion, idPiloto, fecha,
																				destino, cantPasajeros, horaDespegue, horaLlegada);
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^/]/%[^/]/%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idVuelo, idAvion, idPiloto, fechaDia, fechaMes, fechaAnio,
																								destino, cantPasajeros, horaDespegue, horaLlegada)==10)
			{
				pVuelo = vuelo_newParametros(idVuelo, idAvion , idPiloto, fechaDia, fechaMes, fechaAnio, destino, cantPasajeros, horaDespegue, horaLlegada);

				if(pVuelo != NULL)
				{
					ll_add(pListaVuelo, pVuelo);
					rtn = 1;
				}
			}
		}while(!feof(pFile));
	}

	return rtn;
}

int parser_pilotos(FILE* pFile, LinkedList* pListaPilotos)
{
	ePiloto* pPiloto;

	int rtn=0;
	char idPiloto[50];
	char nombre[50];

	if(pFile != NULL && pListaPilotos != NULL)
	{
		fscanf(pFile, "%[^,],%[^\n]\n", idPiloto, nombre);
		do
		{
			if(fscanf(pFile, "%[^,],%[^\n]\n", idPiloto, nombre)==2)
			{
				pPiloto = piloto_newParametros(idPiloto, nombre);

				if(pPiloto != NULL)
				{
					ll_add(pListaPilotos, pPiloto);
					rtn = 1;
				}
			}
		}while(!feof(pFile));
	}

	return rtn;
}
