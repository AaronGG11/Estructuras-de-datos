#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <strings.h>
#include "Sistema.h"
#include "Elem.h"
#include "ArbolBinario.h"
#include "DicBin.h"  
#include "AVL.h"

typedef FILE * aFILE;
void inOrdFile(ArBin, aFILE);

/*
	Programa que mediante el uso de archivos de lectura y escritura, 
	lee un archivo.txt y mete al arbol AVL palabra por palabra (considerendo que no se repitan),
	de repertirse el ocntador de cada palabra se incrementara en uno.
	El arbol AVL, al ser un caso del Diccionario de busqueda binaria, al recorrerlo e imprimirlo 
	en inOrden, el contenido del archivo de salida estara ordenado.
	Para hacer lo anterior se modifico la estructura de ArBin, incluyendo un campo mas en su definicion,
	este es un contador inicalizado en 1. 
*/

int main(int argc, char const *argv[]){
	limpiaPantalla();

	FILE * in = fopen(*(argv+1),"r");
	FILE * out = fopen(*(argv+2),"w");
	char arreglo[100];
	char * x;
	DicBin ent = vacio();
	
	while(fscanf(in,"%s",arreglo)!=EOF){
		x = (char*)malloc(100);
		strcpy(x,"");
		strcpy(x,arreglo);
		ent = insOrd(x,ent);
	}
	inOrdFile(ent,out);

	fclose(in);
	fclose(out);

	inOrd(ent);

	return 0;
}

void inOrdFile(ArBin a, aFILE x){ // izquierdo, raiz, derecho
	if(!esVacio(a)){
		inOrdFile(izq(a),x);
		fprintf(x,"%d - ",contPal(a));
		fprintf(x,"%s\n",raiz(a));
		inOrdFile(der(a),x);
	}
}





