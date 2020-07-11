#include<stdio.h>
#include<stdlib.h>
#include "Elem.h"
#include "Circular.h"


int main(int argc, char *argv[]){

	Circular q = nuevaC();
	for(int i=1; i<=10; i++){
		q=formarC(q,i);
	}

	while(1){
		ImpElem(primeroC(q));
		q = rotar(q);
		if(getchar()=='#')
			exit(0);

	}
	
	/*
	ImpElem(primeroC(q));
	printf("\n");
	rotar(q);
	ImpElem(primeroC(q));
	printf("\n");
	*/

	return 0;


}