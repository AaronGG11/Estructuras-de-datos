#include "ListaA.h"

typedef struct{
  vertice v;
  ListaA adj;
}Elem1;

void ImpElemV(Elem1 e)
{	
	printf("\nVertice:%c\n", e.v);
	printf("\n Aristas \n");
	ImpListaA(e.adj);
	printf("\t");
}

