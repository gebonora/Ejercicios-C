/*
 * 3.c
 *
 *  Created on: Apr 3, 2019
 *      Author: gonzalo
 */


#include "tres.h"

int main (){

	FILE* fp;
	FILE* fpNew;
	fp = fopen ("/home/gonzalo/archivo.txt","r");
	if (fp==NULL){puts("ERROR AL ABIR ARCHIVO"); exit(1);
	}  else puts("ABRIO ARCHIVO OK");

	fpNew = fopen("/home/gonzalo/archivoSalida.txt","w+");
	if (fpNew==NULL){puts("ERROR AL ABIR ARCHIVO"); exit(1);
		}  else puts("ABRIO ARCHIVO OK");

	lista listaBuffer = (lista) malloc(sizeof(lista));
	listaBuffer->informacion=malloc(sizeof(char)*1024);
	listaBuffer->siguiente=NULL;
	iniciarLogger();

	leerYArmarLista(fp,listaBuffer);
	//mostrarLista(listaBuffer);
	//swap(listaBuffer,listaBuffer->siguiente);
	//mostrarLista(listaBuffer);
	ordenarPorRegionYEdad(listaBuffer);
	mostrarLista(listaBuffer);
	escribirEnArchivo(fpNew, listaBuffer);
	fclose(fp);
	return 0;
}

void leerYArmarLista(FILE* fp,lista unaLista){
	char* leido =malloc(sizeof(char)*1024);
	int flag = 1; //para caso 1er elemento
	lista elementoAnterior=unaLista; //apunta al 1er elemento, luego cambia.

	while(fgets(leido,1024,fp)!=NULL){
		lista elementoNuevo = (lista) malloc(sizeof(lista));
		char** arrayLeido = malloc(sizeof(char)*1024*8);
		char ** arrayModificado = malloc(sizeof(char)*1024*8);
		arrayLeido = string_split(leido,";");
		elementoNuevo->informacion =  malloc(sizeof(char)*1024);

		if (atoi(arrayLeido[2])>=18){     //si no es mayor de 18 no lo guardo
			arrayModificado=formatearArray(arrayLeido);

		if (flag==1){//caso 1er elemento
			unaLista->informacion = arrayModificado;
			flag=0;
		}else{
			elementoNuevo->informacion = arrayModificado;
			elementoAnterior->siguiente = elementoNuevo;
			elementoNuevo->siguiente = NULL;
			elementoAnterior=elementoNuevo;
			}
		//flag= 0;
		}
		free(leido);
		free(arrayLeido);
		//fgets(leido,1024,fp) si pones esto de nuevo, no anda
	} //este ciclo recorre el archivo, filtra a los menores de 18, cambia el orden
	  //del string  y guarda la informacion en una lista que recibe por parametro.

	return;

}
char** formatearArray(char** array){
	char ** nuevoArray = malloc(sizeof(char)*1024*8);
	nuevoArray[0]= array[0];
	nuevoArray[1]= array[2];
	nuevoArray[2]= array[4];
	nuevoArray[3]= array[1];
	nuevoArray[4]= array[3];
	nuevoArray[5]= array[5];
	if (atoi(array[5])<100) {log_info(g_logger,array[1]); puts("");}
	return nuevoArray;
}

void iniciarLogger(){
	g_logger = log_create("/home/gonzalo/logEj3.log","Ejercicio3", 0 , LOG_LEVEL_INFO);
}

void ordenarPorRegionYEdad(lista unaLista){
	lista ptr;
	lista lptr = NULL;
	int flag; //un flag

	    do
	    {
	    	flag = 0;
	        ptr = unaLista;
	        while (ptr->siguiente != lptr) //recorre toda la lista
	        {
	        	//strcmp(str1,str2) si str1 es mas chico retorna -1, si son iguales 0, si str2 es mas chico 1.
	        	if(strcmp(ptr->informacion[0],ptr->siguiente->informacion[0])==0){
	        		if(strcmp(ptr->informacion[1],ptr->siguiente->informacion[1])>0){
	        			swap(ptr, ptr->siguiente);
	        			flag = 1;
	        			}
	        		} else if (strcmp(ptr->informacion[0],ptr->siguiente->informacion[0])>0){
	        			swap(ptr, ptr->siguiente);
	        		    flag = 1;

	        	}
	        		ptr = ptr->siguiente;
	        }
	        lptr = ptr;
	    }
	    while (flag); //mientras haya cambiado, sigue
	    //2 ciclos: while anidado en do while
	    return;

}

void swap(lista ant, lista sig ){
	char **temp=malloc(sizeof(char)*1024*8);
	temp = ant->informacion;
	ant->informacion=sig->informacion;
	sig->informacion=temp;
	return;


}

void mostrarLista(lista unaLista){
	lista puntero=unaLista;
	puts("MOSTRAR LISTA");
	while (puntero!=NULL){
		for(int c=0; c<=5;c++){
			puts((puntero->informacion)[c]);
		}
		puntero=puntero->siguiente;
	}return;
}


void escribirEnArchivo(FILE* fp, lista unaLista){
	while(unaLista!=NULL){
		char* string = armarLinea(unaLista->informacion);
		fputs (string,fp);
		unaLista= unaLista->siguiente;
	}
	return;
}

char* armarLinea (char** array){
	char* string = malloc(sizeof(array[0])*8);
	char* formato = " | ";
	int a = 1;
	string = strcpy(string,array[0]);
	while (a<=4){
		char* contenido= array[a];
		string = strcat(string,formato);
		string = strcat(string, contenido);
		a++;
	}
	string=strcat(string,"\n");
	return string;
}




