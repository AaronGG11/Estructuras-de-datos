#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h> 
#include "Elem.h"
#include "Circular.h"
#include "Sistema.h"
#include "Ruleta.h"

int main(int argc, char *argv[]){

	Circular q = nuevaC(); // Genera una cola circular vacia
	Partida p = nuevaP();  // Genera una partida en blanco

	q = generaTablero(q);  // Genera el tablero de la ruleta
	procesoJuego(q,p);     // Donde se desarrolla todo el juego 

	free(p);
	free(q);
	
	return 0;
}











