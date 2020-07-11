#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sistema.h"
#include "Elem.h"
#include "Lista.h" // si importa el orden de las .h


int main(int argc, char * argv[]){
	LimpiaPantalla();

	FILE * in = fopen(*(argv+1),"r");
	char pal1[80], *pal2;
	Lista pals = Vacia();

	while(fscanf(in,"%s",pal1)!=EOF){
		pal2 = (char*)malloc(80);
		strcpy(pal2,pal1);
		pals = Cons(pal2,pals);
	}

	ImpLista(OrdLista(pals));
	fclose(in);
	free(pal2);

	return 0;
}






























	// ImpLista(InvierteLista(MultxN(OrdLista(LeeLista()))));
	// printf("\n");
	//Lista n = Cons(1,Cons(2,Cons(3,Cons(4,Vacia()))));
	//estaEn(4,n)?printf("Cierto\n"):printf("Falso\n");
	//Lista m = Cons(5,Cons(6,Cons(7,Cons(8,Vacia()))));
	//Lista x = Cons(3,Cons(6,Cons(9,Cons(12,Vacia()))));
	// ImpLista(InvierteLista(PegaListas(n,m)));
	// ImpLista(Mult3(x));
	// ImpLista(InvierteLista(Mult3(LeeLista())));
	// Lista n = Cons(2,Cons(3,Cons(4,Vacia())));
	// ImpLista(InvierteLista(InsOrd(9,n)));


















