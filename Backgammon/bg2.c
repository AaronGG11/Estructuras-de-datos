#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h> // Para los temporizadores 
#include "Sistema.h"
#include "Elem.h"
#include "Bicola.h"
#include "Jugador.h"
#include "Dado.h"
#include "Backgammon.h"

int main(int argc, char *argv[]){

	Bicola bq = nuevaB();
	Dados dices = nuevosDados();
	Jugador player1 = nuevoJugador();
	Jugador player2 = nuevoJugador();
	int control = 0;

	bq = generaTablero(bq); // tablero con fichas iniciales
	limpiaPantalla();
	control = asignaTurno(player1,player2,dices); // tiran dados y se asigna el primer turno 
	usleep(3500000); // pausa de 3.5 segundos
	procesoJuego(bq,dices,player1,player2,control);

	return 0;
}






