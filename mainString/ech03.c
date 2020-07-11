// leer palabra por palabras 

#include<stdio.h>


int main(int argc, char * argv[]){
	FILE * ent = fopen(*(argv+1),"r");
	char pal[80];
	while(fscanf(ent,"%s",pal)!=EOF)
		printf("%s\n",pal);

	return 0;
}


/*
	Como funciona en el terminal ?
		1. gcc codigo.c -o codigo 
		2. ./a.out archivo.txt 
*/
