
#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"


int main(int argc, char * argv[]){
	int n;
	int i, j;

	printf("Tamaño de la tabla hash: ");
	scanf("%d",&n);

	Hash h = creaHashTable(n);

	for(i=0; i<n; i++){
		for(j=0; j<=i; j++){
			h[i] = Cons(j,h[i]);
		}
	}

	for(i=0; i<n; i++){
		ImpLista(h[i]);
		puts(" ");
	}


	return 0;
}