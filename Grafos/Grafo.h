#include "ListaV.h"

typedef ListaV Grafo;

Grafo consgr(){	return vaciaV();}

Grafo AgregaVer(Elem1 v,Grafo g){return consv(v,g);}


int Sonadj(Grafo g,vertice v1, vertice v2){
	Grafo t=g;

	while(!EsIgualA(v1,cabezaV(t).v))
	  	t=restoV(t);
	return EstaEnA(v2,t->vertex.adj);
}

ListaA Vecinos(Grafo g,vertice v)
{
	Grafo t=g;
  while(!EsIgualA(v,cabezaV(t).v))
	  	t=restoV(t);
	return t->vertex.adj;
}

Grafo agregaA(Grafo g,vertice v1,vertice v2)
{
	Grafo t=g;
	while(!EsIgualA(cabezaV(t).v,v1))
		t=restoV(t);
	t->vertex.adj=consA(v2,t->vertex.adj);
	t=g;

	while(!EsIgualA(cabezaV(t).v,v2))
		t=restoV(t);
	t->vertex.adj=consA(v1,t->vertex.adj);
	return g;
}

void  RemoverA(Grafo g,vertice v1,vertice v2){
	Grafo t=g;
	Grafo p=g;
	
	while(!EsIgualA(cabezaV(t).v,v1))
		t=restoV(t);
	t->vertex.adj=RemoverAdj(t->vertex.adj,v1);
	t->vertex.adj=RemoverAdj(t->vertex.adj,v2);
	
	while(!EsIgualA(cabezaV(t).v,v1))
		p=restoV(t);
	p->vertex.adj=RemoverAdj(t->vertex.adj,v2);
	p->vertex.adj=RemoverAdj(t->vertex.adj,v1);

}

void ImpGraf(Grafo g){
	ImpListaV(g);
}

int GradoCamino(Grafo g)
{	
	int contador=0;
	
	while(!esvaciaV(g))
	{
		if((NumElem(g->vertex.adj)%2)!=0)
		{
			contador++;
			g=restoV(g);
		}
		else 
			g=restoV(g);
	}
	
	return(contador==2);
}

int GradoCiclo(Grafo g)
{	
	Grafo t=g;
	int contador=0;
	
	while(!esvaciaV(t))
	{
		if((NumElem(t->vertex.adj)%2)==0)
		{
			contador++;
			t=restoV(t);
		}
		else 
			t=restoV(t);
	}	
	return(contador==NumElemV(g));
}
void esEuleriano(Grafo g)
{
	GradoCamino(g)? puts("\nEs Camino Euleriano"):puts("\nNo es Camino Euleriano");
	GradoCiclo(g)? puts("\nEs Ciclo Euleriano"):puts("\nNo es Ciclo Euleriano");
}
Elem1 ElimA(Elem1 e,vertice v)
{
	Elem1 t;
	t.v=e.v;
	t.adj=RemoverAdj(e.adj,v);
	return t;
}

Grafo Limpiar(Grafo g, vertice v)
{
	if(esvaciaV(g))
		return vaciaV();
	else 
		return AgregaVer(ElimA(cabezaV(g),v),Limpiar(restoV(g),v));
}
Grafo RemoveV(Grafo g,vertice v)
{
	if(esvaciaV(g))
		return vaciaV();
	else if(EsIgualA(cabezaV(g).v,v))
			return Limpiar(restoV(g),v);
		else
			return AgregaVer(ElimA(cabezaV(g),v),RemoveV(restoV(g),v));
	
}

int esPuente(Grafo g,vertice v)
{
	return (NumElem(g->vertex.adj)==1);	
}
int esNoPuente(Grafo g,vertice v)
{
	return (NumElem(g->vertex.adj)!=1);	
}

Elem1 Inicio(Grafo g){	
	Grafo t=g;
	if(GradoCamino(t)){
		while((!esvaciaV(t))&&(NumElem(t->vertex.adj)%2)!=0)
			return cabezaV(t);
	}
	else
		return Inicio(restoV(t));
}

Grafo imprimeEuler(Grafo g,vertice u){
	Grafo t=g;
	
	vertice v=cabezaV(restoV(t)).v;

	if(!esvaciaV(t))
	{
		RemoverA(t,u,v);
		printf("\n [%c] a [%c]",u,v);
		t=restoV(t);
		 return imprimeEuler(t,v);
	}
	else
	{
		return NULL;
	}
		
}

