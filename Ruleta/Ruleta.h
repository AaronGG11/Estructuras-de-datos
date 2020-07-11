
typedef struct datos{
	int jugados;
	int perdidos;
	int ganados;
	int dinero; // en cada partida, apuestas
	int saldo;
} * Partida;


int girarRuleta(Circular q){
	int numero, i;

	srand(time(NULL));
	i = rand()%((int)pow(37,5)); //cast a entero
								 //rotara a q, un numero ramdom entre 1 y 37^5 -> hasta 69,000,000
	while(i){
		q = rotar(q);
		i--;
	}

	return primeroC(q);
}

void muestraTablero(int apuesta, Partida x){
	printf("\n\t\t$$ Ruleta $$\n\n");
	printf("\t\t        Tablero\n");
	printf("\t         ---------------------\n");
	printf("\t         |         0         |\n");
	printf("\t------------------------------\n");
	printf("\t|   1º   |  1R \t  2N \t3R   |\n");
	printf("\t| Primer |  4N \t  5R \t6N   |\n");
	printf("\t| grupo  |  7R \t  8N \t9R   |\n");
	printf("\t| docena |  10N\t  11N\t12R  |\n");
	printf("\t------------------------------\n");
	printf("\t|   2º   |  13N\t  14R\t15N  |\n");
	printf("\t| Segundo|  16R\t  17N\t18R  |\n");
	printf("\t| grupo  |  19R\t  20N\t21R  |\n");
	printf("\t| docena |  22N\t  23R\t24N  |\n");
	printf("\t------------------------------\n");
	printf("\t|   3º   |  25R\t  26N\t27R  |\n");
	printf("\t| Tercer |  28N\t  29N\t30R  |\n");
	printf("\t| grupo  |  31N\t  32R\t33N  |\n");
	printf("\t| docena |  34R\t  35N\t36R  |\n");
	printf("\t------------------------------\n");
	printf("\t         |  C1  |  C2 |  C3  |\n");
	printf("\t         ---------------------\n\n");
	printf("\tApuesta minima: $1\n");
	printf("\tApuesta maxima: $50,000\n");
	if(x -> saldo < 1){
		printf("\tSaldo: $%d\n",0);
		x -> saldo = 0;
	}
	else
		printf("\tSaldo: $%d\n", x -> saldo);
	printf("\tApuesta actual: $%d\n\n\n", x -> dinero);
}

void menuApuestas(){
	printf("\t¡Seleccione la forma de apostar!\n");
	printf("\t\ta) Solo un numero\n");
	printf("\t\tb) Numeros Pares\n");
	printf("\t\tc) Numeros Impares\n");
	printf("\t\td) Primeros 18 numeros\n");
	printf("\t\te) Ultimos 18 numeros\n");
	printf("\t\tf) Primer decena\n");
	printf("\t\tg) Segunda decena\n");
	printf("\t\th) Tercer decena\n");
	printf("\t\ti) Decenas 1 & 2\n");
	printf("\t\tj) Decenas 2 & 3\n");
	printf("\t\tk) Numeros Rojos\n");
	printf("\t\tl) Numeros Negros\n\n");
}

Partida nuevaP(){
	Partida temporal = (Partida)malloc(sizeof(struct datos));
	temporal -> jugados = 0;
	temporal -> ganados = 0;
	temporal -> perdidos = 0;
	temporal -> dinero = 0;
	temporal -> saldo = 0;
	return temporal;
}

Partida unNumero(Circular c, Elem n, Partida x){
	int casilla_elegida = girarRuleta(c);
	if(casilla_elegida == n){
		printf("\tVictoria, Numero ganador: %d\n",casilla_elegida);
		x -> ganados += 1;
		x -> saldo += (35*x->dinero);
		printf("\tApuesta: $ %d\n", x -> dinero);  
		x -> dinero = 0 ; 
	}
	else{
		printf("\tDerrota, Numero ganador: %d\n",casilla_elegida);	
		x -> perdidos += 1;
		x -> saldo -= x -> dinero; 
		printf("\tApuesta: $ %d\n", x -> dinero);
		x -> dinero = 0;
	}
	x -> jugados += 1;
	return x;
}

Partida numerosPares(Circular c, Partida x){
	int casilla_elegida = girarRuleta(c);
	int control = 0;
	int contador = 0;
	while(control <= 36){
		if((casilla_elegida != 0)&&(casilla_elegida == control))
			contador += 1;
		control += 2;
	}
	if(contador != 0){
		printf("\tVictoria, Numero ganador: %d\n",casilla_elegida);
		x -> ganados += 1;
		x -> saldo += x-> dinero;
		printf("\tApuesta: $ %d\n", x -> dinero);  
		x -> dinero = 0 ;
	}
	else{
		printf("\tDerrota, Numero ganador: %d\n",casilla_elegida);	
		x -> perdidos += 1; 
		x -> saldo -= x -> dinero;
		printf("\tApuesta: $ %d\n", x -> dinero);
		x -> dinero = 0;
	}

	x -> jugados += 1;
	return x;
}

Partida numerosImpares(Circular c, Partida x){
	int casilla_elegida = girarRuleta(c);
	int control = 0;
	int contador = 0;
	while(control <= 35){
		if((casilla_elegida != 0)&&(casilla_elegida == control)&&(control%2 != 0 ))
			contador += 1;
		control += 1;
	}
	if(contador != 0){
		printf("\tVictoria, Numero ganador: %d\n",casilla_elegida);
		x -> ganados += 1;
		x -> saldo += x -> dinero;
		printf("\tApuesta: $ %d\n", x -> dinero);
		x -> dinero = 0 ;  
	}
	else{
		printf("\tDerrota, Numero ganador: %d\n",casilla_elegida);	
		x -> perdidos += 1; 
		x -> saldo -= x -> dinero;
		printf("\tApuesta: $ %d\n", x -> dinero);
		x -> dinero = 0;
	}

	x -> jugados += 1;
	return x;
}

Partida primeros18N(Circular c, Partida x){
	int casilla_elegida = girarRuleta(c);
	int control = 0;
	int contador = 0;
	while(control <= 18){
		if((casilla_elegida != 0)&&(casilla_elegida == control))
			contador += 1;
		control += 1;
	}
	if(contador != 0){
		printf("\tVictoria, Numero ganador: %d\n",casilla_elegida);
		x -> ganados += 1;
		x -> saldo += x -> dinero;
		printf("\tApuesta: $ %d\n", x -> dinero); 
		x -> dinero = 0 ; 
	}
	else{
		printf("\tDerrota, Numero ganador: %d\n",casilla_elegida);	
		x -> perdidos += 1; 
		x -> saldo -= x -> dinero;
		printf("\tApuesta: $ %d\n", x -> dinero);
		x -> dinero = 0;
	}

	x -> jugados += 1;
	return x;
}

Partida ultimos18N(Circular c, Partida x){
	int casilla_elegida = girarRuleta(c);
	int control = 19;
	int contador = 0;
	while(control <= 36){
		if(casilla_elegida == control)
			contador += 1;
		control += 1;
	}
	if(contador != 0){
		printf("\tVictoria, Numero ganador: %d\n",casilla_elegida);
		x -> ganados += 1;
		x -> saldo += x -> dinero;
		printf("\tApuesta: $ %d\n", x -> dinero); 
		x -> dinero = 0 ; 
	}
	else{
		printf("\tDerrota, Numero ganador: %d\n",casilla_elegida);	
		x -> perdidos += 1; 
		x -> saldo -= x -> dinero;
		printf("\tApuesta: $ %d\n", x -> dinero);
		x -> dinero = 0;
	}
	x -> jugados += 1;
	return x;
}

Partida primerDecena(Circular c, Partida x){
	int casilla_elegida = girarRuleta(c);
	int control = 0;
	int contador = 0;
	while(control <= 12){
		if((casilla_elegida != 0)&&(casilla_elegida == control))
			contador += 1;
		control += 1;
	}
	if(contador != 0){
		printf("\tVictoria, Numero ganador: %d\n",casilla_elegida);
		x -> ganados += 1;
		x -> saldo += (2*x->dinero);
		printf("\tApuesta: $ %d\n", x -> dinero); 
		x -> dinero = 0 ; 
	}
	else{
		printf("\tDerrota, Numero ganador: %d\n",casilla_elegida);	
		x -> perdidos += 1; 
		x -> saldo -= x -> dinero;
		printf("\tApuesta: $ %d\n", x -> dinero);
		x -> saldo -= x -> dinero;
	}

	x -> jugados += 1;
	return x;
}

Partida segundaDecena(Circular c, Partida x){
	int casilla_elegida = girarRuleta(c);
	int control = 13;
	int contador = 0;
	while(control <= 24){
		if(casilla_elegida == control)
			contador += 1;
		control += 1;
	}
	if(contador != 0){
		printf("\tVictoria, Numero ganador: %d\n",casilla_elegida);
		x -> ganados += 1;
		x -> saldo += (2*x->dinero);
		printf("\tApuesta: $ %d\n", x -> dinero);  
		x -> dinero = 0 ;
	}
	else{
		printf("\tDerrota, Numero ganador: %d\n",casilla_elegida);	
		x -> perdidos += 1; 
		x -> saldo -= x -> dinero;
		printf("\tApuesta: $ %d\n", x -> dinero);
		x -> dinero = 0;
	}

	x -> jugados += 1;
	return x;
}


Partida terceraDecena(Circular c, Partida x){
	int casilla_elegida = girarRuleta(c);
	int control = 25;
	int contador = 0;
	while(control <= 36){
		if(casilla_elegida == control)
			contador += 1;
		control += 1;
	}
	if(contador != 0){
		printf("\tVictoria, Numero ganador: %d\n",casilla_elegida);
		x -> ganados += 1;
		x -> saldo += (2*x->dinero);
		printf("\tApuesta: $ %d\n", x -> dinero);  
		x -> dinero = 0 ;
	}
	else{
		printf("\tDerrota, Numero ganador: %d\n",casilla_elegida);	
		x -> perdidos += 1; 
		x -> saldo -= x -> dinero;
		printf("\tApuesta: $ %d\n", x -> dinero);
		x -> dinero = 0;
	}

	x -> jugados += 1;
	return x;
}

Partida primerOrSegundaDecena(Circular c, Partida x){
	int casilla_elegida = girarRuleta(c);
	int control = 0;
	int contador = 0;
	while(control <= 24){
		if((casilla_elegida != 0)&&(casilla_elegida == control))
			contador += 1;
		control += 1;
	}
	if(contador != 0){
		printf("\tVictoria, Numero ganador: %d\n",casilla_elegida);
		x -> ganados += 1;
		x -> saldo += (0.5*x->dinero);
		printf("\tApuesta: $ %d\n", x -> dinero); 
		x -> dinero = 0 ; 
	}
	else{
		printf("\tDerrota, Numero ganador: %d\n",casilla_elegida);	
		x -> perdidos += 1; 
		x -> saldo -= x -> dinero;
		printf("\tApuesta: $ %d\n", x -> dinero);
		x -> dinero = 0;
	}

	x -> jugados += 1;
	return x;
}

Partida segundaOrTerceraDecena(Circular c, Partida x){
	int casilla_elegida = girarRuleta(c);
	int control = 13;
	int contador = 0;
	while(control <= 36){
		if(casilla_elegida == control)
			contador += 1;
		control += 1;
	}
	if(contador != 0){
		printf("\tVictoria, Numero ganador: %d\n",casilla_elegida);
		x -> ganados += 1;
		x -> saldo += (0.5*x->dinero);
		printf("\tApuesta: $ %d\n", x -> dinero);  
		x -> dinero = 0 ;
	}
	else{
		printf("\tDerrota, Numero ganador: %d\n",casilla_elegida);	
		x -> perdidos += 1; 
		x -> saldo -= x -> dinero;
		printf("\tApuesta: $ %d\n", x -> dinero);
		x -> dinero = 0;
	}

	x -> jugados += 1;
	return x;
}

Partida numerosRojos(Circular c, Partida x){
	int casilla_elegida = girarRuleta(c);
	int control = 1;
	int numeros_rojos[]={1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
	int contador = 0;
	while(control <= 18){
		if(casilla_elegida == numeros_rojos[control])
			contador += 1;
		control += 1;
	}
	if(contador != 0){
		printf("\tVictoria, Numero ganador: %d\n",casilla_elegida);
		x -> ganados += 1;
		x -> saldo += x->dinero;
		printf("\tApuesta: $ %d\n", x -> dinero);  
		x -> dinero = 0 ;
	}
	else{
		printf("\tDerrota, Numero ganador: %d\n",casilla_elegida);	
		x -> perdidos += 1; 
		x -> saldo -= x -> dinero;
		printf("\tApuesta: $ %d\n", x -> dinero);
		x -> dinero = 0;
	}

	x -> jugados += 1;
	return x;
}

Partida numerosNegros(Circular c, Partida x){
	int casilla_elegida = girarRuleta(c);
	int control = 2;
	int numeros_rojos[]={2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};
	int contador = 0;
	while(control <= 18){
		if(casilla_elegida == numeros_rojos[control])
			contador += 1;
		control += 1;
	}
	if(contador != 0){
		printf("\tVictoria, Numero ganador: %d\n",casilla_elegida);
		x -> ganados += 1;
		x -> saldo += x->dinero;
		printf("\tApuesta: $ %d\n", x -> dinero);  
		x -> dinero = 0 ;
	}
	else{
		printf("\tDerrota, Numero ganador: %d\n",casilla_elegida);	
		x -> perdidos += 1; 
		x -> saldo -= x -> dinero;
		printf("\tApuesta: $ %d\n", x -> dinero);
		x -> dinero = 0;
	}

	x -> jugados += 1;
	return x;
}

Circular generaTablero(Circular q){
	for(int i=0; i<=36; i++){
		q=formarC(q,i);
	}
	return q;
}

void procesoJuego(Circular q, Partida p){
	int numero_apuesta;
	char seleccion;
	char op;

	do{
		do{
			LimpiaPantalla();
			muestraTablero(p->dinero,p);
			printf("\tTeclee el monto de su apuesta: $ ");
			scanf("%d",&p->dinero);
			if((p->dinero<1)||(p->dinero>50000)){
				p->dinero = 0;
				printf("\tMonto de apuesta no valido, ¡Teclee un monto valido! ");
				getchar();
				getchar();
			}
		}while((p->dinero<1)||(p->dinero>50000));

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
				p = numerosPares(q,p);
					break;
			case 'c':
				p = numerosImpares(q,p); 
					break;
			case 'd': 
				p = primeros18N(q,p);
					break;
			case 'e': 
				p = ultimos18N(q,p);
					break;
			case 'f': 
				p = primerDecena(q,p);
					break;
			case 'g': 
				p = segundaDecena(q,p);
					break;
			case 'h': 
				p = terceraDecena(q,p);
					break;
			case 'i': 
				p = primerOrSegundaDecena(q,p);
					break;
			case 'j': 
				p = segundaOrTerceraDecena(q,p);
					break;
			case 'k': 
				p = numerosRojos(q,p);
					break;

			case 'l':
				p = numerosNegros(q,p);
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
		printf("\tSaldo final: $%d\n\n", p -> saldo);	
	else
		printf("\tSaldo final: $%d\n\n",p -> saldo);
	printf("\t¡Vuelva pronto!\n");
	printf("\n\tGarcia Gonzalez Aaron Antonio E.D.2018\n\n\n");
}