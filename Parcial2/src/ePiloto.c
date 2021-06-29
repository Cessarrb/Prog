#include "ePiloto.h"

ePiloto* piloto_new()
{
	ePiloto* pPiloto;

	pPiloto = (ePiloto*) calloc(sizeof(ePiloto), 1);

	return pPiloto;
}

ePiloto* piloto_newParametros(char* id, char* nombre)
{
	ePiloto* pPiloto;

	pPiloto = piloto_new();

	if(id != NULL && nombre != NULL)
	{
		piloto_setId(pPiloto, atoi(id));
		piloto_setNombre(pPiloto, nombre);
	}

	return pPiloto;
}

int piloto_setId(ePiloto* this, int id)
{
	int rtn=0;

	if(this != NULL && id>0)
	{
		this->idPiloto=id;
		rtn=1;
	}

	return rtn;
}
int piloto_getId(ePiloto* this, int* id)
{
	int rtn=0;

	if(this != NULL && id>0)
	{
		*id=this->idPiloto;
		rtn=1;
	}

	return rtn;
}

int piloto_setNombre(ePiloto* this, char* nombre)
{
	int rtn=0;

	if(this != NULL && strlen(nombre)>0)
	{
		strcpy(this->nombre, nombre);
		rtn=1;
	}

	return rtn;
}
int piloto_getNombre(ePiloto* this, char* nombre)
{
	int rtn=0;

	if(this != NULL && strlen(nombre)>0)
	{
		strcpy(nombre, this->nombre);
		rtn=1;
	}

	return rtn;
}

