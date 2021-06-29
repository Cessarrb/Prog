#ifndef EPILOTO_H_
#define EPILOTO_H_
#include "Input.h"

typedef struct
{
	int idPiloto; //FK
	char nombre[50];
}ePiloto;

ePiloto* piloto_new();
ePiloto* piloto_newParametros(char* id, char* nombre);

int piloto_setId(ePiloto* this, int id);
int piloto_getId(ePiloto* this, int* id);

int piloto_setNombre(ePiloto* this, char* nombre);
int piloto_getNombre(ePiloto* this, char* nombre);

#endif /* EPILOTO_H_ */
