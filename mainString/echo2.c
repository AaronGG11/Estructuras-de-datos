

#include<stdio.h>


int main(int argc, char *argv[]){ // numero de palabras mandadas ,arreglo de cadenas
	
	char c;

	FILE *in = fopen(*++argv,"r");

	while((c=fgetc(in))!=EOF){
		putchar(c);
	}

	return 0;
}

// gcc ./mitype.c -o mitype
// mitype manifiesto.txtint main(int argc, char * argv[]){

/* 
	Pasos para visualizar en pantalla lo que contiene el archivo txt
	1. Compilar este archivo de c:
		gcc archivo.c -o archivo
	2. Escribir lo siguiente en la tarminal
		./a.out doc.txt
*/