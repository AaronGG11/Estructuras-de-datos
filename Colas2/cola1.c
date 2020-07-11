#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sistema.h"
#include "Elem.h"
#include "Cola.h"


int main(int argc, char *argv[]){
	LimpiaPantalla();

	int control;
	Cola q = nueva();
	formar(formar(formar(formar(formar(formar(q,1),2),3),4),5),6);

	printf("Cola original:\n");
	ImpCola(q);
	printf("\n");

	printf("Desformando cola ...\n");
	while(!esNueva(q)){
		ImpCola(q);
		desformar(q);
	}
	printf("\nCola actual: ");
	ImpCola(q);

	return 0;
}











// funcion recursiva que imprima una cola, de tal forma que no altere a la original

/*

	int NumAleatorio(){
		return rand()%10;
	}
	printf("\n--------------------------------------------------\n");
	ImpCola(q);
	printf("\n");

	control=NumAleatorio();
	printf("Cola en espera: %d",control);
	printf("\n");
	while(control){
		formar(q,NumAleatorio());
		control--;
	}

	printf("Cola original:\n");
	ImpCola(q);
	printf("\n");

	printf("Desformando cola ...\n");
	while(!esNueva(q)){
		ImpCola(q);
		desformar(q);
	}
*/

/*
	Cola q = nueva();
	esNueva(q)?puts("1. Cierto"):puts("1. Falso");
	formar(q,1);
	formar(q,2);
	esNueva(q)?puts("2. Cierto"):puts("2. Falso");
	ImpElem(primero(q));
	esNueva(q)?puts("3. Cierto"):puts("3. Falso");
	desformar(q);
	esNueva(q)?puts("4. Cierto"):puts("4. Falso");
	ImpElem(primero(q));
	desformar(q);
	esNueva(q)?puts("5. Cierto"):puts("5. Falso");	
*/