#ifndef PARSER_H_
#define PARSER_H_
#include "Controller.h"
#include "LinkedList.h"
#include "eVuelo.h"
#include "ePiloto.h"

int parser_vuelos(FILE* pFile, LinkedList* pListaVuelo);

int parser_pilotos(FILE* pFile, LinkedList* pListaPilotos);
#endif /* PARSER_H_ */
