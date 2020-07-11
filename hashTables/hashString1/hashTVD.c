#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sistema.h"
#include "ElemHashTable.h"
#include "Lista.h"
#include "Hash.h"
#include "tvd.h"

int main(int argc, char * argv[]){

	FILE * input = fopen(*(argv+1),"rt");
	int num = 12;
	char control; 
	Hash hash = creaHashTable(num);
	hash = addFileToHash(input,hash,num);

	
	printf("%d\n",valueofASCII("Stefan-Salvatore"));
	printf("%d\n",valueofASCII("Stefan-Salvatore")%numPrimoSig(num));
	impElemHT(Cabeza(hash[valueofASCII("Stefan-Salvatore")%numPrimoSig(num)]));
	printf("vrvrvrvgr");

	do{
		//limpiaPantalla();
		Menu(input,hash,num);
		limpiaBuffer();
		printf("\nRealizar otra operacion?(S/N) ");
		scanf("%c",&control);

	}while((control == 'S')||(control == 's'));

	fclose(input);
	return 0;
}