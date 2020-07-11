#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Sistema.h"
#include "ElemHashTable.h"
#include "Lista.h"
#include "Hash.h"
#include "tp.h"

int main(int argc, char * argv[]){

	FILE * input = fopen(*(argv+1),"rt");
	int tam;
	Hash hash = htVacio();

	limpiaPantalla();
	printf("\n\tTeclee el tamaño de la tabla hash: ");
	scanf("%d",&tam);

	tam  = numPrimoSig(tam+1); 
	hash = creaHashTable(tam);
	hash = addFileToHash(input,hash,tam);
	procesoEjecutable(input,hash,tam);

	fclose(input);

	return 0;
}

