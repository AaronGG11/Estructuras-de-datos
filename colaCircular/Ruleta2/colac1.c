#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Elem.h"
#include "Circular.h"
#include "Sistema.h"
#include "Ruleta.h"


int main(int argc, char *argv[]){

	int numero_apuesta;
	char seleccion;
	char op;
	Circular q = nuevaC();
	Partida p = nuevaP();

	for(int i=0; i<=36; i++){
		q=formarC(q,i);
	}

	do{
		do{
			LimpiaPantalla();
			muestraTablero(p->dinero,p);
			printf("\tTeclee el monto de su apuesta: ");
			scanf("%d",&p->dinero);
			if((p->dinero<1)||(p->dinero>500)){
				printf("\tMonto de apuesta no valido, ¡Teclee un monto valido! ");
				getchar();
				getchar();
			}
		}while((p->dinero<1)||(p->dinero>500));

		LimpiaPantalla();
		muestraTablero(p->dinero,p);
		menuApuestas();
		printf("\tTeclee su seleccion: ");
		LimpiaBuffer();
		scanf("%c",&seleccion);
		switch(seleccion){
		case 'a': 
			printf("\tTeclee el elemento a el que apostara: ");
			scanf("%d",&numero_apuesta);
			p = unNumero(q,numero_apuesta,p);	
				break;
		case 'b': 
			p = numerosPares(q,0,p);
				break;
		case 'c':
			p = numerosImpares(q,0,p); 
				break;
		case 'd': 
			p = primeros18N(q,0,p);
				break;
		case 'e': 
			p = ultimos18N(q,0,p);
				break;
		case 'f': 
			p = primerDecena(q,0,p);
				break;
		case 'g': 
			p = segundaDecena(q,0,p);
				break;
		case 'h': 
			p = terceraDecena(q,0,p);
				break;
		case 'i': 
			p = primerOrSegundaDecena(q,0,p);
				break;
		case 'j': 
			p = segundaOrTerceraDecena(q,0,p);
				break;
		case 'k': 
			p = numerosRojos(q,0,p);
				break;

		case 'l':
			p = numerosNegros(q,0,p);
				break;
		}
		LimpiaBuffer();
		printf("\n\n\tVolver a jugar[S/N]: ");
		scanf("%c",&op);
	}while((op =='s')||(op == 'S'));

	LimpiaPantalla();
	printf("\n\tResumen de la partida\n\n");
	printf("\tJuegos Jugados: %d\n",  p -> jugados);
	printf("\tJuegos Ganados: %d\n",  p -> ganados);
	printf("\tJuegos perdidos: %d\n", p -> perdidos);
	if(p -> saldo <= 0)
		printf("\tSaldo final: %d\n\n", 0);	
	else
		printf("\tSaldo final: $%d\n\n",p -> saldo);
	printf("\t¡Vuelva pronto!\n\n\n");

	free(p);
	free(q);
	
	return 0;

}








