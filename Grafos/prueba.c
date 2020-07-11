#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"
 int main() 
 {
   Grafo g=consgr();
   int n,m,origen,destino,i;
   printf("Introduce el numero de vertices de tu grafo: ");
   scanf("%d",&n);
   Elem1 e[n];
   char v[n];
   for(i=0;i<n;i++)
   {
	   printf("Introduce el vertice[%d]: ",i);
	   fflush(stdin);
	   scanf("%c",&v[i]);
	   e[i].v=v[i];
	   e[i].adj=vacia();
	   g=AgregaVer(e[i],g);
	}
	puts("-----Vertices agregados-----");
	for(i=0;i<n;i++)
   		printf("v[%d]='%c'\n",i,v[i]);
	   
	
  printf("Introduce el numero de aristas de tu grafo: ");
   scanf("%d",&m);
   for(i=0;i<m;i++)
   {
	   printf("\nIntroduce la posicion del vertice origen: ");
	   scanf("%d",&origen);
	   printf("\nIntroduce la posicion del vertice destino: ");
	   scanf("%d",&destino);
	   g=agregaA(g,v[origen],v[destino]);
	   printf("\nArista de '%c' a '%c' agregada",v[origen],v[destino]);
	}
   ImpGraf(g);   
   esEuleriano(g);  
   ImpListaA(Vecinos(g,v[0]));
	
	
   return 0;
 }
