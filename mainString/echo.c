#include<stdio.h>


int main(int argc, char *argv[]){ // numero de palabras mandadas ,arreglo de cadenas
	
	while(argc--){
		puts(*argv++);
	}

	return 0;
}