#include "Controller.h"

int controller_cargaDesdeTextoPilotos(char* path, LinkedList* pListaVuelos)
{
	int rtn= 0;

	FILE* pFile;

	if(path != NULL && pListaVuelos != NULL)
	{
		pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			if(parser_pilotos(pFile, pListaVuelos))
			{
				fclose(pFile);
				rtn=1;
			}
		}
	}

	return rtn;

}

int controller_cargaDesdeTextoVuelos(char* path, LinkedList* pListaVuelos)
{
	int rtn= 0;
	FILE* pFile;

	if(path != NULL && pListaVuelos != NULL)
	{
		pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			if(parser_vuelos(pFile, pListaVuelos))
			{
				fclose(pFile);
				rtn=1;
			}
		}
	}

	return rtn;
}

int controller_imprimirVuelos(LinkedList* pListaVuelos, LinkedList* pListaPilotos)
{
	int rtn= 0;

	if(pListaVuelos != NULL)
	{
		if(vuelo_printvuelos(pListaVuelos, pListaPilotos))
		{
			rtn=1;
		}
	}

	return rtn;
}

int controller_cantidadPasajeros(LinkedList* pListaVuelos)
{
	int rtn= 0;


	return rtn;
}
int controller_cantidadPasajerosAChina(LinkedList* pListaVuelos)
{
	int rtn= 0;


	return rtn;
}
