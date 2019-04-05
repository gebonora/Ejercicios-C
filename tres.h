/*
 * 3.h
 *
 *  Created on: Apr 3, 2019
 *      Author: gonzalo
 */

#ifndef EJ3_H_
#define EJ3_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <commons/string.h> //string y log son de las libraries de SO
#include <commons/log.h>

struct nodo{
	char** informacion;
	struct nodo* siguiente;
};
typedef struct nodo* lista;
t_log* g_logger;

void leerYArmarLista(FILE* fp,lista unaLista);
char** formatearArray(char** array);
void iniciarLogger();
void swap(lista ant, lista sig );
void ordenarPorRegionYEdad(lista unaLista);
void mostrarLista(lista unaLista);
void escribirEnArchivo(FILE* fp, lista unaLista);
char* armarLinea (char** array);

#endif /* 3_H_ */
