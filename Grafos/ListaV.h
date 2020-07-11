#include "Elem1.h"

typedef struct NodoV{
  Elem1 vertex;
  struct NodoV *sig;
}*ListaV;

ListaV vaciaV(){return NULL;}

ListaV consv(Elem1 v, ListaV l){
  ListaV t=(ListaV)malloc(sizeof(struct NodoV));
  t->vertex=v;
  t->sig=l;
  return t;
}

int esvaciaV(ListaV l){return l==NULL;}

Elem1 cabezaV(ListaV l){return l->vertex;}

ListaV restoV(ListaV l){return l->sig;}

void ImpListaV(ListaV l){
	if(!esvaciaV(l)){
		ImpElemV(l->vertex);
		ImpListaV(restoV(l));
	}
}

int NumElemV(ListaV l)
{
	if(esvaciaV(l))
		return 0;
		
	else
		return 1+NumElemV(restoV(l));
}
