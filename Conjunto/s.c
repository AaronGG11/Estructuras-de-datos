#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Elem.h"
#include "Lista.h"
#include "Conjunto.h"

int main(int argc, char *argv[]){
	Conjunto a = insertaC('a',insertaC('e',insertaC('i',insertaC('o',insertaC('u',vacioC())))));
	Conjunto b = insertaC('a',insertaC('b',insertaC('c',insertaC('d',insertaC('e',vacioC())))));
	Conjunto c = insertaC('x',insertaC('i',insertaC('y',insertaC('z',vacioC()))));

	printf("Conjunto A\n");
		ImpConjunto(a);
	printf("Conjunto B\n");
		ImpConjunto(b);
	printf("Conjunto Union A B\n");
		ImpConjunto(Union(a,b));
	printf("Conjunto interseccion A B\n");
		ImpConjunto(Interseccion(a,b));
	printf("Conjunto Diferiencia A - B\n");
		ImpConjunto(Diferiencia(a,b));
	printf("Conjunto C union (A - B)\n");
		ImpConjunto(Interseccion(c,Diferiencia(a,b)));


	return 0;
}


/*
	Conjunto s1 = insertaC(1,insertaC(2,insertaC(3,insertaC(4,vacioC()))));
	Conjunto s2 = insertaC(6,insertaC(4,insertaC(5,insertaC(3,vacioC()))));
	Conjunto s3 = OrdConjunto(Union(s1,s2));
	Conjunto s4 = OrdConjunto(Interseccion(s1,s2));
	Conjunto s5 = OrdConjunto(Diferiencia(s1,s2));
	Conjunto s6 = OrdConjunto(Diferiencia(s2,s1));

	ImpConjunto(s3);
	printf("\n");
	ImpConjunto(s4);
	printf("\n");
	ImpConjunto(s5);
	printf("\n");
	ImpConjunto(s6);
	printf("\ncardinalidad s1: %d\n",Cardinalidad(s1));
	printf("cardinalidad s2: %d\n",Cardinalidad(s2));
*/