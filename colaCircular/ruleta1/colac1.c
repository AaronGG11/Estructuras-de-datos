#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Sistema.h"
#include "Elem.h"
#include "Circular.h"

int girarRuleta(Circular);


int main(int argc, char *argv[]){
	limpiaPantalla();

	Circular q = nuevaC();
	int numApuesta;
	int jugados = 0, perdidos = 0, ganados = 0;
	char op = 's';

	for(int i=0; i<=36; i++){
		q=formarC(q,i);
	}

	// ImpColaC(q); -> imprime el primero de la cola, de forma infinita
	
	do{
		printf("Teclee el numero a apostar: ");
		scanf("%d",&numApuesta);

		printf("Resultado de la ruleta: ");
		ImpElem(girarRuleta(q));

		girarRuleta(q)==numApuesta?printf("Winner\n"),ganados++:printf("Loser\n"),perdidos++;
		jugados++;

		limpiaBuffer();
		printf("Girar de nuevo[S/N]?: ");
		scanf("%c",&op);
	}while((op == 's')||(op == 'S'));

	printf("\nResumen de la partida\n");
	printf("Juegos Jugados: %d\n", jugados);
	printf("Juegos Ganados: %d\n", ganados);
	printf("Juegos perdidos: %d\n", perdidos);

	return 0;

}



int girarRuleta(Circular q){
	int numero, i;

	srand(time(NULL));
	i = rand()%((int)pow(37,2)); //cast a entero
								 //rotara a q, un numero ramdom entre 0 y 37^2
	while(i){
		q = rotar(q);
		i--;
	}

	return primeroC(q);
	
}









