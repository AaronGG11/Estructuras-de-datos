// leer y mandar a un archivo 

#include<stdio.h>


int main(int argc, char * argv[]){
	FILE * ent = fopen(*(argv+1),"r"), *sal = fopen(*(argv+2),"w");
	char pal[80];
	while(fscanf(ent,"%s",pal)!=EOF)
		//printf("%s\n",pal);
		fprintf(stdout,"%s\n",pal); // stdout = pantalla
	fclose(ent);
	fclose(sal);

	return 0;
}


/*	Para ejecutarl oen la terminal:
		1. Compilar
			gcc codigo.c
		2. terminal 
			./a.out origen.txt destino.txt
	*/