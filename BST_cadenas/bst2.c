
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sistema.h"
#include "Elem.h"
#include "DicBin.h"

void impElemCad(Elem e, FILE * file){ // puntero a fichero
	fprintf(file,"%s \n", e);
}

void inOrdCad(ArBin a, FILE * file){ // izquierdo, raiz, derecho
	if(!esVacio(a)){
		inOrdCad(izq(a),file);
		impElemCad(raiz(a),file);
		inOrdCad(der(a),file);
	}
}

int main(int argc, char *argv[]){ 

	LimpiaPantalla();
	FILE * in = fopen(*(argv+1),"r");
	FILE * out = fopen(*(argv+2),"wt");
	char pal1[20000], *pal2;
	DicBin pals = vacio();
	DicBin temp = vacio();

	while(fscanf(in,"%s",pal1)!=EOF){
		pal2 = (char*)malloc(80);
		strcpy(pal2,pal1);
		pals = insOrd(pal2,pals);
	}

	inOrdCad(pals,out);

	fclose(in);
	fclose(out);
	free(pal2);

	return 0;
}



