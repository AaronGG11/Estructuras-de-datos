#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Sistema.h"
#include "Elem.h"
#include "ArbolBinario.h"
#include "DicBin.h"  
#include "AVL.h"
#include "arregloNumeros.h"

int main() {

	srand (time(NULL));

	int i, numeros;
	AVL a = vacio();

	printf("Numeros? ");
	scanf("%d",&numeros);

	int numeroAleatorio[numeros];
	generaNumeros(numeroAleatorio,numeros);

	for(i=0; i<numeros; i++){
		printf("%d\n",numeroAleatorio[i]);
	} // COMPROBAR LOS NUMEROS


	for(i=0; i<numeros; i++){
		a = consAVL(numeroAleatorio[i],a);
		printf("%d",factBal(a));
	} // METER AL ARBOL LOS NUMEROS

	inOrd(a); // IMPRIMIR EN ORDEN
	printf("\n\n\n");
	impAVL(a,0); // IMPRIMIR AVL, CONTADOR IGUAL A CERO 
	printf("\n\n\n");

	printf("El minimo es: %d\n",minElem(a));

    return 0;

}
