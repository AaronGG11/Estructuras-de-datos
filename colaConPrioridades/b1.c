#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "Bicola.h"
#include "Sistema.h"

int main(int argc, char *argv[]){
	Bicola q = nuevaB();

	formarConPrioridad(2,q);
	formarConPrioridad(3,q); 
	formarConPrioridad(4,q);
	formarConPrioridad(1,q);
	formarConPrioridad(5,q);
	formarConPrioridad(8,q);
	formarConPrioridad(6,q);
	formarConPrioridad(9,q);
	formarConPrioridad(7,q);
	formarConPrioridad(15,q);
	formarConPrioridad(12,q);
	formarConPrioridad(11,q);
	formarConPrioridad(14,q);
	formarConPrioridad(10,q);
	formarConPrioridad(13,q);
	ImpColaD(q);

	return 0;
}


