#include<stdio.h>
#include<stdlib.h>
#include "Elem.h"
#include "Cola.h"


int main(int argc, char *argv[]){
	
	Cola q = nueva();
	formar(q,1);
	ImpElem(primero(q));


	return 0;
}

// funcion recursiva que imprima una cola, de tal forma que no altere a la original


