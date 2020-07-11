#include<stdio.h>


int main(int argc, char * argv[]){

	char * pal = *(argv + 1);
	int i=0;

	
	do{
		printf("%c\n",*pal); // repasar * y & 
	} while(*(++pal));	
	

	// while(putchar(*pal++)putchar('\n'));
	// while(putchar(pal[i++]));

	return 0;
}


/*
	Que sucede en la terminal?
	1. Lo compilas y luego ./a.out cadena
	Como lo hace ? 
		crear una variable de tipo apuntador a caracter, esta apuntara a argv +1, que sera la cadena 
		que se le manda a 
*/