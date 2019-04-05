/*
 * dos.h
 *
 *  Created on: 31 mar. 2019
 *      Author: Gonzalo
 */

/*Enunciado:
Se pide modelar un TAD que represente un Archivo, se debe poder abrir (definir la forma: read/write/append), cerrar
un archivo, leer una linea determinada, exponer una operación que reciba una función y la ejecute por cada línea del
archivo; exponer otra operación que dada una lista y una función, itere la lista y escriba sobre el archivo abierto lo que
devuelve dicha función (string).
*/
//https://sites.google.com/site/programacioniiuno/temario/unidad-2---tipo-abstracto-de-dato/implementacin-de-un-tda-en-c

#ifndef DOS_H_
#define DOS_H_

// el Archivo
typedef FILE ARCHIVO;

typedef enum{
	read,
	write,
	append
}modo_de_apertura;

// Lista

typedef struct elemento_lista{
	char* cadena;
	struct elemento_lista* siguiente;
}lista;


//funciones

ARCHIVO* abrir(char* nombre_archivo, modo_de_apertura modo);
void cerrar(ARCHIVO* puntero);
char* leer_linea(ARCHIVO* puntero, int numero_de_linea);
void operar(void(*puntero_a_funcion)(char*),ARCHIVO* puntero); //toma una funcion void que necesita un char* como parametro
void operar_lista(void(*puntero_a_funcion)(char*),ARCHIVO* puntero,lista* puntero_de_lista); //igual que el anterior, pero toma una lista de strings

#endif /* DOS_H_ */
