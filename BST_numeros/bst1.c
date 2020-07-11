#include <stdio.h>
#include <stdlib.h>
#include "Sistema.h"
#include "Elem.h"
#include "DicBin.h"

	/*
		Ejecutar el .c, despues teclear numero a numero con espacios y al final teclear un 0 y enter, 
		se van a imprimir todos los numeros en inOrd, de tal forma que estaran ordenados de menor a mayor
	*/

int main(int argc, char *argv[]){ 

	int x;

	DicBin a = vacio();

	do{
		scanf("%d",&x);
		a = insOrd(x,a);
	}while(x);

	inOrd(a);

	return 0;
}
