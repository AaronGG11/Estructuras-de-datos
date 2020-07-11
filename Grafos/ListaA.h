#include "vertice.h"

typedef struct Nodo{
  vertice va;
  struct Nodo *sig;
}*ListaA;

ListaA vacia(){return NULL;}

ListaA consA(vertice v, ListaA l){
  ListaA t=(ListaA) malloc(sizeof (struct Nodo));
	t->va = v;
	t->sig = l;
	return t;
}

int esvaciaA(ListaA l){return l==NULL;}

vertice cabeza(ListaA l){return l->va;}

ListaA resto(ListaA l){return l->sig;}

void ImpListaA(ListaA l) {
  if(!esvaciaA(l)){
    ImpVer(cabeza(l));
    ImpListaA(resto(l));
  }
}

int EstaEnA( char c, ListaA l){
  if(esvaciaA(l))
    return 0;
  else if(l->va==c)
    return 1;
  else
    return EstaEnA(c,resto(l));
}

ListaA RemoverAdj(ListaA l,vertice v)
{
	if(esvaciaA(l))
		return vacia();
	else if(EsIgualA(cabeza(l),v))
		return resto(l);
		  else
		  	return consA(cabeza(l),RemoverAdj(resto(l),v));
}
int NumElem(ListaA l)
{
	if(esvaciaA(l))
		return 0;
		
	else
		return 1+NumElem(resto(l));
}



