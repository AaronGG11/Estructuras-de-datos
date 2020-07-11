
typedef struct partida{
	char equipo[11]; // positivas o negativas
	int fichasLiberadas; // al final 
	int fichasRetenidas; // comidas
	int suma_dados; // la suma de sus dados por tiro 
	int turno; // cada tiro 
	int ficha; // positivos, negativos en numero
} * Jugador;

Jugador nuevoJugador(){
	Jugador temporal = (Jugador)malloc(sizeof(struct partida));
	temporal -> fichasLiberadas = 0;
	temporal -> fichasRetenidas = 0;
	temporal -> suma_dados = 0;
	temporal -> turno = 0;
	temporal -> ficha = 0;
	strcpy(temporal -> equipo, "");
	
	return temporal;
}

