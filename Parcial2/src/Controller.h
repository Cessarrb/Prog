#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "eVuelo.h"
#include "ePiloto.h"
#include "LinkedList.h"
#include "Parser.h"
#include "input.h"

int controller_cargaDesdeTextoPilotos(char* path, LinkedList* pListaVuelos);
int controller_cargaDesdeTextoVuelos(char* path, LinkedList* pListaVuelos);
int controller_imprimirVuelos(LinkedList* pListaVuelos, LinkedList* pListaPilotos);
int controller_cantidadPasajeros(LinkedList* pListaVuelos);
int controller_cantidadPasajerosAChina(LinkedList* pListaVuelos);


#endif /* CONTROLLER_H_ */
