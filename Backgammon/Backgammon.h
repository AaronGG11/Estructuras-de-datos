
Bicola generaTablero(Bicola b){ // Tablero con las 24 posiciones y las fichas iniciales 

	int p_iniciales[] = {0,5,7,11,12,16,18,23};
	int v_iniciales[] = {2,-5,-3,5,-5,3,5,-2};
	int i, j;

	for(i=0;i <24; i++){
		formarI(0,b);
		for(j=0; j<9; j++){
			if(p_iniciales[j] == i)
				b -> entrada -> dato = v_iniciales[j];
		}
	}
	return b;
}

int asignaTurno(Jugador a, Jugador b, Dados d){
	printf("\n\n\t <<< WELCOME TO BACKGAMMON >>>\n");
	srand(time(NULL));
	printf("\n\tJugador 1, tire sus dados!");
	pausaPrograma();
	 
	d = tirarDados();
	impDados_turno(d);
	a -> suma_dados = d -> dado_1 + d -> dado_2;

	usleep(500000); // pausa de 2.5 segundos
	printf("\n\tJugador 2, tire sus dados!");
	pausaPrograma();
 
	do{
		d = tirarDados(); 
		b -> suma_dados = d -> dado_1 + d -> dado_2;
	}while(sonIgualesTiros(a,b));
	impDados_turno(d);

	if(esMayor(a,b)){ //
		printf("\tJugador 1: Fichas positivas <-, comienzas!\n");
		printf("\tJugador 2: Fichas negativas ->\n\n");
		a -> turno = 1; 
		strcpy(a -> equipo, "FPositivas");
		strcpy(b -> equipo, "FNegativas");
		return 1;
	}
	else{
		printf("\tJugador 1: Fichas negativas ->\n");
		printf("\tJugador 2: Fichas positivas <-, comienzas!\n\n");
		b -> turno = 1;
		strcpy(b -> equipo, "FPositivas");
		strcpy(a -> equipo, "FNegativas");
		return 2;
	}
}

void impTablero(Bicola b, Jugador x, Jugador y, int c){

	Bicola temporal = nuevaB();
	temporal -> entrada = b -> entrada;
	temporal -> salida = b -> salida;
	int a[24];

	limpiaPantalla();

	for(int i=0; i<24; i++){
		a[i] = i+1;
	}

	printf("\n\n\t\t\t\t  <<< BACKGAMMON >>>\n\n\t");
	printf("----------------------------------------------------------------------------\n\t|");
	for(int i=12; i<24; i++){
		if(i == 17)
			printf(" %d | |", a[i]);
		else if((i<23)&&(i!=17))
			printf(" %d -", a[i]);
		else
			printf(" %d |", a[i]);
	}
	printf(" F Pos. : %d |", x -> fichasLiberadas);
	printf("\n\t|-----------------------------| |-------------------------------------------\n");

	while(temporal -> salida -> index != 13){
		temporal -> salida = temporal -> salida -> anterior;
	}
	printf("\t|");
	while(temporal -> salida != NULL){
		if(temporal -> salida -> index == 18){
			ImpElem(temporal -> salida -> dato);
			printf("| |");
			temporal -> salida = temporal -> salida -> anterior;
		}
		else if((temporal -> salida -> index <23)&&(temporal -> salida -> index != 18)){
			ImpElem(temporal -> salida -> dato);
			printf("| ");
			temporal -> salida = temporal -> salida -> anterior;
		}
		else{
			ImpElem(temporal -> salida -> dato);
			printf(" |");	
			temporal -> salida = temporal -> salida -> anterior;
		}
	}
	printf("\n\t|-----------------------------| |-------------------------------------------\n");
	printf("\t|                             | |                             |\n");
	printf("\t|                             | |                             |\n");
	printf("\t|                             | |                             |\n");
	printf("\t|                             | |                             |\n");
	printf("\t|                             | |                             |\n");
	printf("\t|                             | |                             |\n");
	printf("\t|-----------------------------| |-------------------------------------------\n\t|");

	while(temporal -> entrada -> index != 12){
		temporal -> entrada = temporal -> entrada -> siguiente;
	}

	while(temporal -> entrada != NULL){
		if(temporal -> entrada -> index == 7){
			ImpElem(temporal -> entrada -> dato);
			printf("| |");
			temporal -> entrada = temporal -> entrada -> siguiente;
		}
		else if((temporal -> entrada -> index != 7)&&(temporal -> entrada -> index <2)){
			ImpElem(temporal -> entrada -> dato);
			printf(" |");
			temporal -> entrada = temporal -> entrada -> siguiente;
		}
		else{
			ImpElem(temporal -> entrada -> dato);
			printf("| ");
			temporal -> entrada = temporal -> entrada -> siguiente;
		}
	}
	printf("\n\t|-----------------------------| |-------------------------------------------\n\t|");
	for(int i=11; i>=0	; i--){
		if(i>9)
			printf(" %d -", a[i]);
		else if((i<=9)&&(i>6))
			printf(" %d  -", a[i]);
		else if(i == 6)
			printf(" %d | |", a[i]);
		else if((i<6)&&(i>=1))
			printf("  %d -", a[i]);
		else
			printf("  %d | F Neg. : %d |\n", a[i], y -> fichasLiberadas);			
	}
	printf("\t|---------------------------------------------------------------------------\n");

	if(c == 1){
		printf("\n\tJugador: %d <- Fichas positivas pendientes: %d\n", c, y->fichasRetenidas);
		printf("\tJugador: %d -> Fichas negativas pendientes: %d\n", c+1, x->fichasRetenidas);
	}else{
		printf("\n\tJugador: %d <- Fichas positivas pendientes: %d\n", c, x->fichasRetenidas);
		printf("\tJugador: %d -> Fichas negativas pendientes: %d\n\n\n", c-1, y->fichasRetenidas);	
	}	
}

int esVaciaCasilla(Bicola b, int casilla){ // tablero y casilla 
	Bicola temporal = nuevaB();
	temporal -> entrada = b -> entrada;
	temporal -> salida = b -> salida;

	while(temporal -> salida -> index != casilla){
		temporal -> salida = temporal -> salida -> anterior;
	}
	return temporal -> salida -> dato == 0;
}

int esMismoEquipo(Bicola b, int ficha, int posDes){ // tablero, ficha y posicion destino 
	// 0 si no es mismo equipo, 1 si lo es, 2 si esta vacia
	Bicola temporal = nuevaB();
	temporal -> entrada = b -> entrada;
	temporal -> salida = b -> salida;

	if(esVaciaCasilla(b,posDes))
		return 2;

	while(temporal -> salida -> index != posDes){
		temporal -> salida = temporal -> salida -> anterior;
	}

	if(ficha > 0) // positivos
		return temporal -> salida -> dato > 0;
	else if(ficha < 0)
		return temporal -> salida -> dato < 0;
	else 
		return 0;
}

int numFichasCasilla(Bicola b, int casilla){ // tablero y casilla -> averigua el numero de fichas que hay en determinada casilla 
	Bicola temporal = nuevaB();
	temporal -> entrada = b -> entrada;
	temporal -> salida = b -> salida;

	if(!esVaciaCasilla(b,casilla)){
		while(temporal -> salida -> index != casilla){
			temporal -> salida = temporal -> salida -> anterior;
		}
		return temporal -> salida -> dato;
	}
	else
		return 0;

	free(temporal);
}

int hayFichasRetenidas(Jugador x){
	return x -> fichasRetenidas > 0;
}

int puedeMoverFichaRetenida(Bicola b, Dados d, Jugador x){
	int posDes = 0;
	int contador = 0;

	if(hayFichasRetenidas(x)){
		if(x -> ficha > 0){ // ficha positiva
			posDes = d -> dado_1; // posibilidad con dado 1
			if(esVaciaCasilla(b,posDes))
				contador += 1;
			else if((!esVaciaCasilla(b,posDes))&&(esMismoEquipo(b,1,posDes)))
				contador += 1;
			else if((!esVaciaCasilla(b,posDes))&&(!esMismoEquipo(b,1,posDes))){
				if(numFichasCasilla(b,posDes) == -1)
					contador += 1;
				else 
					contador += 0;
			}
			else
				contador += 0;

			posDes = d -> dado_2; // posibilidad con dado 2
			if(esVaciaCasilla(b,posDes))
				contador += 1;
			else if((!esVaciaCasilla(b,posDes))&&(esMismoEquipo(b,1,posDes)))
				contador += 1;
			else if((!esVaciaCasilla(b,posDes))&&(!esMismoEquipo(b,1,posDes))){
				if(numFichasCasilla(b,posDes) == -1)
					contador += 1;
				else 
					contador += 0;
			}
			else
				contador += 0; 
		}
		else{ // ficha negativa
			posDes = 24 - d -> dado_1; 
			if(esVaciaCasilla(b,posDes))
				contador += 1;
			else if((!esVaciaCasilla(b,posDes))&&(esMismoEquipo(b,-1,posDes)))
				contador += 1;
			else if((!esVaciaCasilla(b,posDes))&&(!esMismoEquipo(b,-1,posDes))){
				if(numFichasCasilla(b,posDes) == 1)
					contador += 1;
				else
					contador += 0;
			}
			else
				contador += 0;

			posDes = 24 - d -> dado_2; 
			if(esVaciaCasilla(b,posDes))
				contador += 1;
			else if((!esVaciaCasilla(b,posDes))&&(esMismoEquipo(b,-1,posDes)))
				contador += 1;
			else if((!esVaciaCasilla(b,posDes))&&(!esMismoEquipo(b,-1,posDes))){
				if(numFichasCasilla(b,posDes) == 1)
					contador += 1;
				else
					contador += 0;
			}
			else
				contador += 0;
		}
	}
	if(contador != 0)
		return 1;
	else
		return 0;
}


int puedeMoverFichaNoRetenida(Bicola b, Dados d, Jugador x){ // general, solo sirve para despues de tirar dados 

	Bicola temporal = nuevaB(); // checar al final si se ocupa 
	temporal -> salida = b -> salida;
	temporal -> entrada = b -> entrada;
	int posDes = 0;
	int posIni = 0;
	int contador = 0;
	int cont = 0;

	if(hayFichasRetenidas(x)){ // si hay fichas retenidas
		return puedeMoverFichaRetenida(b,d,x);
	}
	else{ // Si no hay fichas retenidas
		if(x -> ficha > 0){ // buscar las fichas positivas
			for(int i=1; i<=23; i++){
				if(temporal -> salida -> dato > 0)
					cont += 1;
				temporal -> salida = temporal -> salida -> anterior;
			}
			if(cont == 0){
				return 0;
				exit(1);
			}
			else{
			temporal -> salida = b -> salida;
			for(int i=1; i<=23; i++){ // recorrer el tablero
				if(temporal -> salida -> dato > 0){ // positivos 
					posIni = i; // temporal -> salida -> index
					posDes = posIni + d -> dado_1; // posibilidad con dado 1
					if(posDes <= 24){ // evitar que se salga del tablero 
						if(esVaciaCasilla(b,posDes))
							contador += 1;
						//else if((!esVaciaCasilla(b,posDes))&&(esMismoEquipo(b,1,posDes)))
						else if((!esVaciaCasilla(b,posDes))&&(esMismoEquipo(b,1,posDes)))
							contador += 1;
						//else if((!esVaciaCasilla(b,posDes))&&(!esMismoEquipo(b,1,posDes))){
						else if((!esVaciaCasilla(b,posDes))&&(!esMismoEquipo(b,1,posDes))){
							if(numFichasCasilla(b,posDes) == -1)
								contador += 1;
						}
						else
							contador += 0;
					}				
					posDes = posIni + d -> dado_2; // posibilidad con dado 12
					if(posDes <= 24){ // evitar que se salga del tablero 
						if(esVaciaCasilla(b,posDes))
							contador += 1;
						else if((!esVaciaCasilla(b,posDes))&&(esMismoEquipo(b,1,posDes)))
							contador += 1;
						else if((!esVaciaCasilla(b,posDes))&&(!esMismoEquipo(b,1,posDes))){
							if(numFichasCasilla(b,posDes) == -1)
								contador += 1;
						else
							contador += 0;
						}						
					}
					else
						contador += 0;

					posDes = posIni + d -> dado_1_2; // posibilidad con dado 12
					if(posDes <= 24){ // evitar que se salga del tablero 
						if(esVaciaCasilla(b,posDes))
							contador += 1;
						else if((!esVaciaCasilla(b,posDes))&&(esMismoEquipo(b,1,posDes)))
							contador += 1;
						else if((!esVaciaCasilla(b,posDes))&&(!esMismoEquipo(b,1,posDes))){
							if(numFichasCasilla(b,posDes) == -1)
								contador += 1;
						else
							contador += 0;
						}						
					}
					else
						contador += 0;

					posDes = posIni + d -> dado_2_2; // posibilidad con dado 12
					if(posDes <= 24){ // evitar que se salga del tablero 
						if(esVaciaCasilla(b,posDes))
							contador += 1;
						else if((!esVaciaCasilla(b,posDes))&&(esMismoEquipo(b,1,posDes)))
							contador += 1;
						else if((!esVaciaCasilla(b,posDes))&&(!esMismoEquipo(b,1,posDes))){
							if(numFichasCasilla(b,posDes) == -1)
								contador += 1;
						else
							contador += 0;
						}						
					}
					else
						contador += 0;
				}
				temporal -> salida = temporal -> salida -> anterior;
			}
		}
		}
		else{ // buscar fichas negativas
			for(int i=23; i>=1; i--){ // recorrer el tablero
				if(temporal -> entrada -> dato < 0){
					posIni = i+1; // temporal -> entrada -> index
					posDes = posIni - d -> dado_1; // posibilidad con dado 1
					if(posDes >= 1){ // evitar que se salga del tablero 
						if(esVaciaCasilla(b,posDes))
							contador += 1;
						else if((!esVaciaCasilla(b,posDes))&&(esMismoEquipo(b,-1,posDes)))
							contador += 1;
						else if((!esVaciaCasilla(b,posDes))&&(!esMismoEquipo(b,-1,posDes))){
							if(numFichasCasilla(b,posDes) == 1)
								contador += 1;
						else
							contador += 0;
						}						
					}
					posDes = posIni - d -> dado_2; // posibilidad con dado 1
					if(posDes >= 24){ // evitar que se salga del tablero 
						if(esVaciaCasilla(b,posDes))
							contador += 1;
						else if((!esVaciaCasilla(b,posDes))&&(esMismoEquipo(b,-1,posDes)))
							contador += 1;
						else if((!esVaciaCasilla(b,posDes))&&(!esMismoEquipo(b,-1,posDes))){
							if(numFichasCasilla(b,posDes) == 1)
								contador += 1;
						else
							contador += 0;
						}						
					}
					posDes = posIni - d -> dado_1_2; // posibilidad con dado 1
					if(posDes >= 1){ // evitar que se salga del tablero 
						if(esVaciaCasilla(b,posDes))
							contador += 1;
						else if((!esVaciaCasilla(b,posDes))&&(esMismoEquipo(b,-1,posDes)))
							contador += 1;
						else if((!esVaciaCasilla(b,posDes))&&(!esMismoEquipo(b,-1,posDes))){
							if(numFichasCasilla(b,posDes) == 1)
								contador += 1;
						else
							contador += 0;
						}						
					}
					posDes = posIni - d -> dado_2_2; // posibilidad con dado 1
					if(posDes >= 1){ // evitar que se salga del tablero 
						if(esVaciaCasilla(b,posDes))
							contador += 1;
						else if((!esVaciaCasilla(b,posDes))&&(esMismoEquipo(b,-1,posDes)))
							contador += 1;
						else if((!esVaciaCasilla(b,posDes))&&(!esMismoEquipo(b,-1,posDes))){
							if(numFichasCasilla(b,posDes) == 1)
								contador += 1;
						else
							contador += 0;
						}						
					}
				}
				temporal -> salida = temporal -> salida -> anterior;
			}
		}
		if(contador > 0)
			return 1;
		else
			return 0;
	}
	free(temporal);
}

int puedeMoverFichaRetenidaSeleccion(Bicola b, Dados d, Jugador x, int posDes){ // ya se garantizo que hay retenidas
	// el usuario indica cual podria ser su seleccion a partir de una ficha retenida 
	int contador = 0;

	if(x -> ficha > 0){ // fichas positivas
		if((posDes == d -> dado_1)||(posDes == d -> dado_2)||(posDes == d -> dado_2_2)||(posDes == d -> dado_1_2)){ // talvez podria mover la ficha deseada (dados 1 y 2)
			if(esVaciaCasilla(b,posDes))
				contador += 1;
			else if((!esVaciaCasilla(b,posDes))&&((esMismoEquipo(b,1,posDes))))
				contador += 1;
			else if((!esVaciaCasilla(b,posDes))&&((!esMismoEquipo(b,1,posDes)))){
				if(numFichasCasilla(b,posDes) == -1)
					contador += 1;
			else
				contador += 0;
			}
		}
	}
	else{ // fichas negativas 
		if((posDes = 24 - d -> dado_1)||(posDes = 24 - d -> dado_2)||(posDes = 24 - d -> dado_1_2)||(posDes = 24 - d -> dado_2_2)){ // talvez y para ambos dados
			if(esVaciaCasilla(b,posDes))
				contador += 1;
			else if((!esVaciaCasilla(b,posDes))&&((esMismoEquipo(b,1,posDes))))
				contador += 1;
			else if((!esVaciaCasilla(b,posDes))&&((!esMismoEquipo(b,1,posDes)))){
				if(numFichasCasilla(b,posDes) == -1)
					contador += 1;
			else
				contador += 0;
			}
		}
	}
	if(contador != 0)
		return 1;
	else
		return 0;
}


int puedeMoverFichaNoRetenidaSeleccion(Bicola b, Dados d, Jugador x, int posIn, int posDes){
	// ya se garantizo que no hay fichas retenidas
	int contador = 0;

	if(x -> ficha > 0){ // fichas positivas
		if(!esVaciaCasilla(b,posIn)){ // tiene fichas para mover ? 
			if(esMismoEquipo(b,1,posIn)){ // si es de mi equipo la puedo mover
				if((esVaciaCasilla(b,posDes))||(esMismoEquipo(b,1,posDes))){
					if((posIn + d -> dado_1 == posDes)||(posIn + d -> dado_2 == posDes)||(posIn + d -> dado_1_2 == posDes)||(posIn + d -> dado_2_2 == posDes ))
						contador += 1; // ^ si alguno de los dados satisg¡face lo anterior 
				}
				else if((!esVaciaCasilla(b,posDes))&&(!esMismoEquipo(b,1,posDes))){
					if(numFichasCasilla(b,posDes) == -1){
						if((posIn + d -> dado_1 == posDes)||(posIn + d -> dado_2 == posDes)||(posIn + d -> dado_1_2 == posDes)||(posIn + d -> dado_2_2 == posDes))
							contador += 1; // ^ si alguno de los dados satisg¡face lo anterior 	
					}
				}
				else
					contador += 0;
			}
			else
				printf("La ficha que intenta mover es del otro jugador\n");
		}
		else
			printf("Casilla vacia\n");
	}
	else{ // fichas negativas 
		if(!esVaciaCasilla(b,posIn)){ // tiene fichas para mover ? 
			if(esMismoEquipo(b,-1,posIn)){ // si es de mi equipo la puedo mover
				if((esVaciaCasilla(b,posDes))||(esMismoEquipo(b,-1,posDes))){			
					if((posIn - d -> dado_1 == posDes)||(posIn - d -> dado_2 == posDes)||(posIn - d -> dado_1_2 == posDes)||(posIn - d -> dado_1_2 == posDes))
						contador += 1; // ^ si alguno de los dados satisg¡face lo anterior 
				}
				else if((!esVaciaCasilla(b,posDes))&&(!esMismoEquipo(b,-1,posDes))){
					if(numFichasCasilla(b,posDes) == 1){
						if((posIn - d -> dado_1 == posDes)||(posIn - d -> dado_2 == posDes)||(posIn - d -> dado_1_2 == posDes)||(posIn - d -> dado_2_2 == posDes))
							contador += 1; // ^ si alguno de los dados satisg¡face lo anterior 					
					}
				}
				else
					contador += 0;
			}
			else
				printf("La ficha que intenta mover es del otro jugador\n");
		}
		else
			printf("Casilla vacia\n");
	}
	if(contador != 0)
		return 1;
	else
		return 0;
}

ApNodo getApCasilla(Bicola b, Jugador x, int posDestino){ // solo para casilla destino 
	Bicola temporal = nuevaB();
	temporal -> entrada = b -> entrada;
	temporal -> salida = b -> salida;

	if(x -> ficha > 0){
		while(temporal -> salida -> index != posDestino)
			temporal -> salida = temporal -> salida -> anterior;
		return temporal -> salida;
	}
	else{
		while(temporal -> entrada -> index != posDestino)
			temporal -> entrada = temporal -> entrada -> siguiente;
		return temporal -> entrada;
	}
}

/// 

void moverFichaRetenida(Bicola b, Dados d, Jugador x, Jugador y, int posDes){

	Bicola temporal = nuevaB();
	temporal -> entrada = b -> entrada;
	temporal -> salida = b -> salida;

	// En este punto ya se asumio que se puede mover la ficha, por lo que ya no se validara eso

	if( x -> ficha > 0){ // fichas positivas
		if(esVaciaCasilla(b,posDes)){ 
			x -> fichasRetenidas -= 1;
			temporal -> salida = getApCasilla(b,x,posDes);
			temporal -> salida -> dato = 1;
		}
		else if((!esVaciaCasilla(b,posDes))&&((esMismoEquipo(b,1,posDes)))){
			x -> fichasRetenidas -= 1;
			temporal -> salida = getApCasilla(b,x,posDes);
			temporal -> salida -> dato += 1;
		}
		else if((!esVaciaCasilla(b,posDes))&&((!esMismoEquipo(b,1,posDes)))){
			if(numFichasCasilla(b,posDes) == -1){
				x -> fichasRetenidas -= 1;
				y -> fichasRetenidas += 1;
				temporal -> salida = getApCasilla(b,x,posDes);
				temporal -> salida -> dato = 1;
			}
		}
		else
			printf("\n\tError\n");

		if(sonDadosDobles(d)){ // dados dobles
			if(d -> dado_2_2 > 0)
				d -> dado_2_2 = 0;
			else
				d -> dado_1_2 = 0;
		}
		else{ 
			if(d -> dado_1 == d -> dado_2){
				d -> dado_2 = 0;
			}
			else{
				if(posDes == d -> dado_1)
					d -> dado_1 = 0;
				else
					d -> dado_2 = 0;
			}
		}
	}
	else{ // fichas negativas
		if(esVaciaCasilla(b,posDes)){ 
			x -> fichasRetenidas -= 1;
			temporal -> salida = getApCasilla(b,x,posDes);
			temporal -> salida -> dato = -1;
		}
		else if((!esVaciaCasilla(b,posDes))&&((esMismoEquipo(b,-1,posDes)))){
			x -> fichasRetenidas -= 1;
			temporal -> salida = getApCasilla(b,x,posDes);
			temporal -> salida -> dato -= 1;
		}
		else if((!esVaciaCasilla(b,posDes))&&((!esMismoEquipo(b,-1,posDes)))){
			if(numFichasCasilla(b,posDes) == 1){
				x -> fichasRetenidas -= 1;
				y -> fichasRetenidas += 1;
				temporal -> salida = getApCasilla(b,x,posDes);
				temporal -> salida -> dato = -1;
			}
		}
		else
			printf("\n\tError\n");

		if(sonDadosDobles(d)){ // dados dobles
			if(d -> dado_2_2 > 0)
				d -> dado_2_2 = 0;
			else
				d -> dado_1_2 = 0;
		}
		else{ 
			if(d -> dado_1 == d -> dado_2)
				d -> dado_2 = 0;
			else{
				if(24 - posDes == d -> dado_1)
					d -> dado_1 = 0;
				else
					d -> dado_2 = 0;
			}
		}
	}
	free(temporal);
}

void moverFichaNoRetenida(Bicola b, Dados d, Jugador x, Jugador y,int posIni, int posDes){

	Bicola temporal = nuevaB();
	temporal -> entrada = b -> entrada;
	temporal -> salida = b -> salida;	

	// En este punto ya se asumio que se puede mover la ficha, por lo que ya no se validara eso

	if( x -> ficha > 0){ // fichas positivas
		if(esVaciaCasilla(b,posDes)){ 
			temporal -> salida = getApCasilla(b,x,posIni);
			temporal -> salida -> dato -= 1;
			temporal -> salida = getApCasilla(b,x,posDes);
			temporal -> salida -> dato = 1;
		}
		else if((!esVaciaCasilla(b,posDes))&&((esMismoEquipo(b,1,posDes)))){
			temporal -> salida = getApCasilla(b,x,posIni);
			temporal -> salida -> dato -= 1;
			temporal -> salida = getApCasilla(b,x,posDes);
			temporal -> salida -> dato += 1;
		}
		else if((!esVaciaCasilla(b,posDes))&&((!esMismoEquipo(b,1,posDes)))){
			if(numFichasCasilla(b,posDes) == -1){
				y -> fichasRetenidas += 1;
				temporal -> salida = getApCasilla(b,x,posIni);
				temporal -> salida -> dato -= 1;
				temporal -> salida = getApCasilla(b,x,posDes);
				temporal -> salida -> dato = 1;
			}
		}
		else
			printf("\n\tError\n");

		if(sonDadosDobles(d)){ // dados dobles
			if(d -> dado_2_2 > 0)
				d -> dado_2_2 = 0;
			else
				d -> dado_1_2 = 0;
		}
		else{ //if(!sonDadosDobles(d)){ // dados sencillos 
			if(d -> dado_1 == d -> dado_2){
				d -> dado_2 = 0;
			}
			else{
				if(posDes- posIni == d -> dado_1)
					d -> dado_1 = 0;
				if(posDes - posIni == d -> dado_2)
					d -> dado_2 = 0;			
			}
		}
	}
	else{ // fichas negativas
		if(esVaciaCasilla(b,posDes)){ 
			temporal -> entrada = getApCasilla(b,x,posIni);
			temporal -> entrada -> dato += 1;
			temporal -> entrada = getApCasilla(b,x,posDes);
			temporal -> entrada -> dato -= 1;
		}
		else if((!esVaciaCasilla(b,posDes))&&((esMismoEquipo(b,-1,posDes)))){
			temporal -> entrada = getApCasilla(b,x,posIni);
			temporal -> entrada -> dato += 1;
			temporal -> entrada = getApCasilla(b,x,posDes);
			temporal -> entrada -> dato -= 1;
		}
		else if((!esVaciaCasilla(b,posDes))&&((!esMismoEquipo(b,-1,posDes)))){
			if(numFichasCasilla(b,posDes) == 1){
				y -> fichasRetenidas += 1;
				temporal -> entrada = getApCasilla(b,x,posIni);
				temporal -> entrada -> dato += 1;
				temporal -> entrada = getApCasilla(b,x,posDes);
				temporal -> entrada -> dato = -1;
			}
		}
		else 
			printf("\n\tError\n");

		if(sonDadosDobles(d)){ // dados dobles
			if(d -> dado_2_2 > 0)
				d -> dado_2_2 = 0;
			else
				d -> dado_1_2 = 0;
		}
		else{ //if(!sonDadosDobles(d)){ // dados sencillos 
			if(d -> dado_1 == d -> dado_2)
				d -> dado_2 = 0;
			else{
				if(posIni - posDes == d -> dado_1)
					d -> dado_1 = 0;
				if(posIni - posDes == d -> dado_2)
					d -> dado_2 = 0;
			}
		}
	}
	free(temporal);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

int hayFicPosCassillaExt(Bicola b){
	Bicola temporal = nuevaB();
	temporal -> entrada = b -> entrada;
	temporal -> salida = b -> salida;
	int contador = 0;

	for(int i=1; i<=18; i++){
		if(temporal -> salida -> dato > 0)
			contador += 1;
		temporal -> salida = temporal -> salida -> anterior;
	}

	if(contador == 0)
		return 0;
	else	
		return 1;
	free(temporal);
}

int hayFicNegCassillaExt(Bicola b){
	Bicola temporal = nuevaB();
	temporal -> entrada = b -> entrada;
	temporal -> salida = b -> salida;
	int contador = 0;

	for(int i=24; i>=7; i--){
		if(temporal -> entrada -> dato < 0)
			contador += 1;
		temporal -> entrada = temporal -> entrada -> siguiente;
	}
	if(contador == 0)
		return 0;
	else	
		return 1;
	free(temporal);
}

int puedeSacarFichas(Bicola b, Dados d, Jugador x){

	Bicola temporal = nuevaB();
	temporal -> entrada = b -> entrada;
	temporal -> salida = b -> salida;
	int contador = 0;

	if(hayFichasRetenidas(x))
		return 0;
	else{
		if(x -> ficha > 0){ // fichas positivas
			contador = hayFicPosCassillaExt(b);
		}
		else{ // Fcihas negativas 
			contador = hayFicNegCassillaExt(b);
		}
		if(contador == 0)
			return 1;
		else
			return 0;
	}
	free(temporal);
}

void sacarFicha(Bicola b, Dados d, Jugador x, Jugador y, int posIni){
	Bicola temporal = nuevaB();
	temporal -> entrada = b -> entrada;
	temporal -> salida = b -> salida;
	int posDes;

	if(puedeSacarFichas(b,d,x)){ // tal vez se elimine al final este if
		if(x -> ficha > 0){ // fichas positivas
			if(((posIni + d -> dado_1) <= 24)||((posIni + d -> dado_2) <= 24)){ // posibilidad dado 1 y 2
				printf("\tTeclee la posicion destino: ");
				scanf("%d",&posDes);
				if(puedeMoverFichaNoRetenidaSeleccion(b,d,x,posIni,posDes))
					moverFichaNoRetenida(b,d,x,y,posIni,posDes);
			}
			else{ // directamente saca la ficha que quiera
				for(int i=1; i<=posIni; i++){
					temporal -> salida = temporal -> salida -> anterior;
				}
				temporal -> salida -> dato -= 1;
				x -> fichasLiberadas += 1;
			}
		}
		else{ // fichas negativas
			if(((posIni - d -> dado_1) >= 1)||((posIni - d -> dado_2) >= 1)){ // posibilidad dado 1 y 2
				printf("\tTeclee la posicion destino: ");
				scanf("%d",&posDes);
				if(puedeMoverFichaNoRetenidaSeleccion(b,d,x,posIni,posDes))
					moverFichaNoRetenida(b,d,x,y,posIni,posDes);
			}
			else{
				for(int i=24; i>=posIni; i--){
					temporal -> entrada = temporal -> entrada -> siguiente;
				}
				temporal -> entrada -> dato += 1;
				x -> fichasLiberadas += 1;			
			}
		}

		if(sonDadosDobles(d)){ // dados dobles
			if(d -> dado_2_2 > 0)
				d -> dado_2_2 = 0;
			else
				d -> dado_1_2 = 0;
		}
		else{ //if(!sonDadosDobles(d)){ // dados sencillos 
			if(d -> dado_1 == d -> dado_2){
				d -> dado_2 = 0;
			}
			else{
				if(posDes- posIni == d -> dado_1)
					d -> dado_1 = 0;
				if(posDes - posIni == d -> dado_2)
					d -> dado_2 = 0;			
			}
		}
	}
	free(temporal);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////


void procesoJuego(Bicola b, Dados d, Jugador x, Jugador y, int control){
	int casilla, ficha, posInicial, posDestino, turno = 0;
	// donde turno es como un switch de 0 y 1 

	if(control == 1)
		impTablero(b,x,y,control);
	else
		impTablero(b,y,x,control); 

	if(control == 1){
		x -> turno = 1;
		x -> ficha = 1;
		y -> turno = 0;
		y -> ficha = -1;
	}
	else{
		x -> turno = 0;
		x -> ficha = -1;
		y -> turno = 1;
		y -> ficha = 1;
	}

	while((x -> fichasLiberadas < 15)&&(y -> fichasLiberadas < 15)){
		limpiaPantalla();
		if(x -> turno == 1){ // sabemos que x es positvo y y es negativo
			impTablero(b,x,y,control); // 
			printf("\n\tJugador: %d, Tire los dados!\n",1);
			limpiaBuffer();
			pausaPrograma();
			d = tirarDados();
			impDados(d);
			x -> suma_dados = sumarDados(d);
			if(hayFichasRetenidas(x)&&(x->suma_dados>0)){ // fichas retenidas
				printf("\tHAY FICHAS RETENIDAS\n");
				if(!puedeMoverFichaRetenida(b,d,x))
					printf("\tNo es posible mover ninguna ficha\n");
				else{
					while(((x->suma_dados)>0)&&(puedeMoverFichaRetenida(b,d,x))){
						printf("\tTecle la casilla destino de la ficha: ");
						scanf("%d",&posDestino);
						if(puedeMoverFichaRetenidaSeleccion(b,d,x,posDestino)){
							moverFichaRetenida(b,d,x,y,posDestino);
							printf("\tFicha ha sido trasladada con exito\n");
						}
						else
							printf("\tNo es posible mover la ficha seleccionada\n");
						x -> suma_dados = sumarDados(d);

						usleep(1000000);
						limpiaPantalla();
						impTablero(b,x,y,control);
						impDados(d);
					}
				}
			}
			x -> suma_dados = sumarDados(d);
			if(!hayFichasRetenidas(x)&&(x->suma_dados>0)){ // no hay fichas retenidas
				if((!puedeMoverFichaNoRetenida(b,d,x))) // No hay fichas retenidas en jugador 1  
					printf("\tNo es posible mover ninguna ficha\n");
				else{
					while((x->suma_dados>0)&&(!hayFichasRetenidas(x))){
						if(puedeSacarFichas(b,d,x)){
							printf("\tPuede liberar fichas!\n");
							printf("\tTecle la casilla inicial de la ficha: ");
							scanf("%d",&posInicial);
							sacarFicha(b,d,x,y,posInicial);	
						}
						else{
							printf("\tTecle la casilla inicial de la ficha: ");
							scanf("%d",&posInicial);
							printf("\tTecle la casilla destino de la ficha: ");
							scanf("%d",&posDestino);
							if(puedeMoverFichaNoRetenidaSeleccion(b,d,x,posInicial,posDestino)){
								moverFichaNoRetenida(b,d,x,y,posInicial,posDestino);
								printf("\tFicha ha sido trasladada con exito\n");
							}
							else
								printf("\tNo es posible mover la ficha seleccionada\n");
							x -> suma_dados = sumarDados(d);
						}
						usleep(1000000);
						limpiaPantalla();
						impTablero(b,x,y,control);
						impDados(d);
					}
				}
			}
			x -> turno = 0;
			y -> turno = 1;
		}
		if(y -> turno == 1){ // sabemos que y es positvo y x es negativo 
			impTablero(b,y,x,control);
			printf("\n\tJugador: %d, Tire los dados!\n",2);
			limpiaBuffer();
			pausaPrograma();
			d = tirarDados();
			impDados(d);

			y -> suma_dados = sumarDados(d);
			if(hayFichasRetenidas(y)&&(y->suma_dados>0)){ // fichas retenidas
				printf("\tHAY FICHAS RETENIDAS\n");
				if((!puedeMoverFichaRetenida(b,d,y)))
					printf("\tNo es posible mover ninguna ficha\n");
				else{
					while((y->suma_dados>0)&&(puedeMoverFichaRetenida(b,d,y))){
						printf("\tTecle la casilla destino de la ficha: ");
						scanf("%d",&posDestino);
						if(puedeMoverFichaRetenidaSeleccion(b,d,y,posDestino)){
							moverFichaRetenida(b,d,y,x,posDestino);
							printf("\tFicha ha sido trasladada con exito\n");
						}
						else
							printf("\tNo es posible mover la ficha seleccionada\n");
						y -> suma_dados = sumarDados(d);

						usleep(1000000);
						limpiaPantalla();
						impTablero(b,y,x,control);
						impDados(d);
					}
				}
			}
			y -> suma_dados = sumarDados(d);
			if(!hayFichasRetenidas(y)&&(y->suma_dados>0)){ // no hay fichas retenidas
				if((!puedeMoverFichaNoRetenida(b,d,y))) // No hay fichas retenidas en jugador 1  
					printf("\tNo es posible mover ninguna ficha\n");
				else{
					while((y->suma_dados>0)&&(!hayFichasRetenidas(y))){
						if(puedeSacarFichas(b,d,y)){
							printf("\tPuede liberar fichas!\n");
							printf("\tTecle la casilla inicial de la ficha: ");
							scanf("%d",&posInicial);
							sacarFicha(b,d,y,x,posInicial);	
						}
						else{
							printf("\tTecle la casilla inicial de la ficha: ");
							scanf("%d",&posInicial);
							printf("\tTecle la casilla destino de la ficha: ");
							scanf("%d",&posDestino);
							if(puedeMoverFichaNoRetenidaSeleccion(b,d,y,posInicial,posDestino)){
								moverFichaNoRetenida(b,d,y,x,posInicial,posDestino);
								printf("\tFicha ha sido trasladada con exito\n");
							}
							else
								printf("\tNo es posible mover la ficha seleccionada\n");
							y -> suma_dados = sumarDados(d);							
						}
						usleep(1000000);
						limpiaPantalla();
						impTablero(b,y,x,control);
						impDados(d);
					}
				}
			}
			x -> turno = 1;
			y -> turno = 0;
		}
		limpiaBuffer();
		usleep(2000000);
	}
}
































