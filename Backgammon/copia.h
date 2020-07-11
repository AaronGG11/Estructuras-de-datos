



		if(!sonDadosDobles(d)){ // dados sencillos // forzozamente d1 y d2 son iguales si provienen de dobles 
			// en este punto puede y si eran dobles ya solo sean dobles mitad
			if(sonDadosDoblesMitad(d))
				d -> dado_1 = 0;

			if((posIni - posDes) == d -> dado_1)
				d -> dado_1 = 0;
			if((posIni - posDes) == d -> dado_2)
				d -> dado_2 = 0;
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
			if(d -> dado_1 > 0)
				d -> dado_1 = 0;
			else if((d -> dado_1 == 0)&&(d -> dado_2 > 0))
				d -> dado_2 = 0;
			else if((d -> dado_1 == 0)&&(d -> dado_2 == 0)&&( d -> dado_1_2 > 0))
				d -> dado_1_2 = 0;
			else if((d -> dado_1 == 0)&&(d -> dado_2 == 0)&&( d -> dado_1_2 == 0)&&(d -> dado_2_2 > 0))
				d -> dado_2_2 = 0;
			else
				d -> dado_2_2 = d -> dado_2_2;
		}
		if(!sonDadosDobles(d)){ // dados sencillos 
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
		if(!sonDadosDobles(d)){ // dados sencillos 
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
				if(posDes == d -> dado_2)
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
				if(24 - posDes == d -> dado_2)
					d -> dado_2 = 0;
			}
		}
	}
	free(temporal);
}

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

	(contador == 0)?return 0: return 1;
	free(temporal);
}

int hayFicNegCassillaExt(Bicola b){
	Bicola temporal = nuevaB();
	temporal -> entrada = b -> entrada;
	temporal -> salida = b -> salida;
	int contador = 0;

	for(int i=24; i>=7; i--){
		if(temporal -> salida -> dato < 0)
			contador += 1;
		temporal -> entrada = temporal -> entrada -> siguiente;
	}

	(contador == 0)?return 0: return 1;
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
		if(x -> fichas > 0){ // fichas positivas
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
}

void sacarFicha(Bicola b, Dados d, Jugador x, Jugador y, int posIni){
	Bicola temporal = nuevaB();
	temporal -> entrada = b -> entrada;
	temporal -> salida = b -> salida;
	int posDes;

	if(puedeSacarFichas(b,d,x)){ // tal vez se elimine al final este if
		if(x -> ficha > 0){ // fichas positivas
			if(((posIni + d -> dado_1) <= 24)||((posIni + d -> dado_2) <= 24)){ // posibilidad dado 1 y 2
				printf("Teclee la posicion destino: ");
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
				printf("Teclee la posicion destino: ");
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
		if(temporal -> salida -> dato < 0)
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
		usleep(2000000);
		limpiaBuffer();
	}
}




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
		usleep(2000000);
		limpiaBuffer();
	}
}











