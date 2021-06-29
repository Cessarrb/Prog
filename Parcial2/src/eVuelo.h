#ifndef EVUELO_H_
#define EVUELO_H_
#include "LinkedList.h"
#include "input.h"
#include "ePiloto.h"

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int idVuelo;
	int idAvion;
	int idPiloto; //PK
	char destino [50];
	int cantPasajeros;
	int horaDespegue;
	int horaLlegada;
	eFecha fecha;
}eVuelo;

eVuelo* vuelo_new();
eVuelo* vuelo_newParametros(char* id, char* idAvion, char* idPiloto, char* dia, char* mes, char* anio, char* destino,  char* cantPasajeros, char* horaDespegue, char* horaLlegada);

int Vuelo_Menu();
int vuelo_setId(eVuelo* this, int id);
int vuelo_getId(eVuelo* this, int* id);

int vuelo_setIdAvion(eVuelo* this, int id);
int vuelo_getIdAvion(eVuelo* this, int* id);

int vuelo_setIdPiloto(eVuelo* this, int id);
int vuelo_getIdPiloto(eVuelo* this, int* id);

int vuelo_setDestino(eVuelo* this, char* destino);
int vuelo_getDestino(eVuelo* this, char* destino);

int vuelo_setHoraDespegue(eVuelo* this, int horaDespegue);
int vuelo_getHoraDespegue(eVuelo* this, int* horaDespegue);

int vuelo_setHoraLlegada(eVuelo* this, int horaLlegada);
int vuelo_getHoraLlegada(eVuelo* this, int* horaLlegada);

int vuelo_setFecha(eVuelo* this, int dia, int mes, int anio);
int vuelo_getFecha(eVuelo* this, int* dia, int* mes, int* anio);

int vuelo_setCantPasajeros(eVuelo* this, int cantPasajeros);
int vuelo_getCantPasajeros(eVuelo* this, int* cantPasajeros);

int vuelo_printvuelos(LinkedList* pListaVuelos, LinkedList* pListaPilotos);
#endif /* EVUELO_H_ */
