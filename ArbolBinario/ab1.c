#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "ArbolBinario.h"
#include "Sistema.h"


int main(int argc, char *argv[]){
	ArBin ab = vacio();
	LimpiaPantalla();
	ab = consA(4,consA(1,vacio(),vacio()),consA(6,consA(5,vacio(),vacio()),consA(7,vacio(),vacio())));
	printf("\n\nEl numero de nodos en el arbol es: %d\n", numElem(ab));

	inOrd(ab);
	printf("\n");
	preOrd(ab);
	printf("\n");
	posTorDer(ab);
	printf("\n");

	printf("\n\nLa altura del arbol es: %d\n\n", alturaArbol(ab));

	esHoja(ab)?printf("El arbol es hoja\n"):printf("El arbol no es hoja\n");
	esHoja(izq(ab))?printf("El izquierdo del arbol es hoja\n"):printf("El izquierdo del arbol no es hoja\n");

	return 0;
}

/*
Los arboles se pueden recorrer de tres maneras
	inOrder	(izquierdo,raiz,derecho)
	preOrder(raiz,izquierdo,derecho)
	posTorDer(izquierdo,derecho,raiz)

*/