/*
 * uno.c
 *
 *  Created on: 28 mar. 2019
 *      Author: Gonzalo
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* string_concat(const char*, const char*);
void string_concat_dinamyc(const char*, const char*, char**);
void mail_split(const char* mail, char** user, char** dominio);

int main(){
	// declaraciones punto 3
	char* email= "elbuenusuario@gmail.com";
	char* usuario = calloc(1,sizeof(email));
	char* direccion = calloc(1,sizeof(email));
	//punto1
	char* kerrighan = "Kerrighan ";
	char* y = "y ";
	char* ritchie = "Ritchie";
	char* saludo = string_concat("hola ","chau");
	char* grosos = string_concat(kerrighan,y);
	char* grosos2 = string_concat(grosos,ritchie);

	//punto2

	char* punto2Nombre= "Newton ";
	char* punto2Hola= "Hola ";
	char* puntero=(char*) calloc(50,sizeof(char)); //con malloc quedaba basura, porque malloc no inicializa, calloc si.
	char* puntero2=(char*) calloc(50,sizeof(char));
	string_concat_dinamyc(punto2Hola, punto2Nombre, &puntero);
	string_concat_dinamyc("qwe ", "rtyu", &puntero2);

	//punto 3
	mail_split(email,&usuario,&direccion);


	//printfs
	printf("	Punto1:\n%s\n",saludo);
	printf("%s\n",grosos2);
	puts("	Punto2:");
	printf("%s\n",puntero);
	printf("%s\n",puntero2);
	puts("	Punto3:");
	puts(usuario);
	puts(direccion);



	return 0;

}

char* string_concat(const char* string1, const char* string2){
	char* buffer= malloc(sizeof(char)*50);
	strcpy(buffer, string1);
	strcat(buffer, string2);
	return buffer;


}

void string_concat_dinamyc(const char* string1, const char* string2, char** string3){
	strcat(*string3,string1);
	strcat(*string3,string2);

}

void mail_split(const char* mail, char** user, char** dominio){
	*dominio = strchr(mail, '@');
	(*dominio)++;
	strncat(*user, mail, strlen(mail)-strlen(*dominio)-1);

}

