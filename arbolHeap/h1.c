
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Elem.h"
#include "Lista.h"
#include "ArbolBinario.h"
#include "Heap.h"

Lista llenaLista(FILE*,Lista);
void inOrdH(ArBin,FILE*);

int main(int argc, char *argv[]){
 
	FILE * in = fopen(*(argv+1),"rt"); // Aputador a archivo de entrada en formato lectura
	FILE * out = fopen(*(argv+2),"wt"); // Apuntador a archivo de salida en formato de escritura

	Lista list = Vacia(); // Crea una lista vacia
	Heap arbol = vacio(); // Crea un arbol vacio

	list = llenaLista(in,list); // Llena la lista con un archivo
	arbol = insertElems(list,arbol); // Inserta elementos al arbol y con cada insercion el arbol es completo
	consHeap(arbol); // Hace heap al arbol
	inOrdH(arbol,out); // Imprime en inOrden el arbol 

	fclose(in); // Cierra el puntero del archivo de entrada
	fclose(out); // Cierra el puntero del archivo de salida

	return 0;
}










Lista llenaLista(FILE * input, Lista l){
	char pal[20];
	char * cpal;

	while(fscanf(input,"%s",pal) != EOF){
		cpal = (char*)malloc(20);
		strcpy(cpal,pal);
		l = InsOrd(cpal,l);
	}
	free(cpal);
	return l;
}

void inOrdH(ArBin a, FILE * output){ // izquierdo, raiz, derecho
	if(!esVacio(a)){
		inOrdH(izq(a),output);
		fprintf(output,"%s\n",raiz(a));
		inOrdH(der(a),output);
	}
}








