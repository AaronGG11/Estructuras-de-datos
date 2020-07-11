
typedef struct datos{
	int jugados;
	int perdidos;
	int ganados;
	int dinero;
	int saldo;
} * Partida;


int girarRuleta(Circular q){
	int numero, i;

	srand(time(NULL));
	i = rand()%((int)pow(37,5)); //cast a entero
								 //rotara a q, un numero ramdom entre 0 y 37^5
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
	printf("\tApuesta maxima: $500\n");
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
		x -> saldo += 35;
		printf("\tApuesta: $%d\n", x -> dinero);   
	}
	else{
		printf("\tDerrota, Numero ganador: %d\n",casilla_elegida);	
		x -> perdidos += 1;
		x -> saldo -= x -> dinero; 
		x -> dinero = 0;
		printf("\tApuesta: $%d\n", x -> dinero);
	}
	x -> jugados += 1;
	return x;
}

Partida numerosPares(Circular c, Elem cero, Partida x){
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
		x -> saldo += 35;
		printf("\tApuesta: $%d\n", x -> dinero);  
	}
	else{
		printf("\tDerrota, Numero ganador: %d\n",casilla_elegida);	
		x -> perdidos += 1; 
		x -> saldo -= x -> dinero;
		x -> dinero = 0;
		printf("\tApuesta: $%d\n", x -> dinero);
	}

	x -> jugados += 1;
	return x;
}

Partida numerosImpares(Circular c, Elem cero, Partida x){
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
		x -> saldo += 35;
		printf("\tApuesta: $%d\n", x -> dinero);  
	}
	else{
		printf("\tDerrota, Numero ganador: %d\n",casilla_elegida);	
		x -> perdidos += 1; 
		x -> saldo -= x -> dinero;
		x -> dinero = 0;
		printf("\tApuesta: $%d\n", x -> dinero);
	}

	x -> jugados += 1;
	return x;
}

Partida primeros18N(Circular c, Elem cero, Partida x){
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
		x -> saldo += 35;
		printf("\tApuesta: $%d\n", x -> dinero);  
	}
	else{
		printf("\tDerrota, Numero ganador: %d\n",casilla_elegida);	
		x -> perdidos += 1; 
		x -> saldo -= x -> dinero;
		x -> dinero = 0;
		printf("\tApuesta: $%d\n", x -> dinero);
	}

	x -> jugados += 1;
	return x;
}

Partida ultimos18N(Circular c, Elem cero, Partida x){
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
		x -> saldo += 35;
		printf("\tApuesta: $%d\n", x -> dinero);  
	}
	else{
		printf("\tDerrota, Numero ganador: %d\n",casilla_elegida);	
		x -> perdidos += 1; 
		x -> saldo -= x -> dinero;
		x -> dinero = 0;
		printf("\tApuesta: $%d\n", x -> dinero);
	}
	x -> jugados += 1;
	return x;
}

Partida primerDecena(Circular c, Elem cero, Partida x){
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
		x -> saldo += 35;
		printf("\tApuesta: $%d\n", x -> dinero);  
	}
	else{
		printf("\tDerrota, Numero ganador: %d\n",casilla_elegida);	
		x -> perdidos += 1; 
		x -> saldo -= x -> dinero;
		x -> dinero = 0;
		printf("\tApuesta: $%d\n", x -> dinero);
	}

	x -> jugados += 1;
	return x;
}

Partida segundaDecena(Circular c, Elem cero, Partida x){
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
		x -> saldo += 35;
		printf("\tApuesta: $%d\n", x -> dinero);  
	}
	else{
		printf("\tDerrota, Numero ganador: %d\n",casilla_elegida);	
		x -> perdidos += 1; 
		x -> saldo -= x -> dinero;
		x -> dinero = 0;
		printf("\tApuesta: $%d\n", x -> dinero);
	}

	x -> jugados += 1;
	return x;
}


Partida terceraDecena(Circular c, Elem cero, Partida x){
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
		x -> saldo += 35;
		printf("\tApuesta: $%d\n", x -> dinero);  
	}
	else{
		printf("\tDerrota, Numero ganador: %d\n",casilla_elegida);	
		x -> perdidos += 1; 
		x -> saldo -= x -> dinero;
		x -> dinero = 0;
		printf("\tApuesta: $%d\n", x -> dinero);
	}

	x -> jugados += 1;
	return x;
}

Partida primerOrSegundaDecena(Circular c, Elem cero, Partida x){
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
		x -> saldo += 35;
		printf("\tApuesta: $%d\n", x -> dinero);  
	}
	else{
		printf("\tDerrota, Numero ganador: %d\n",casilla_elegida);	
		x -> perdidos += 1; 
		x -> saldo -= x -> dinero;
		x -> dinero = 0;
		printf("\tApuesta: $%d\n", x -> dinero);
	}

	x -> jugados += 1;
	return x;
}

Partida segundaOrTerceraDecena(Circular c, Elem cero, Partida x){
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
		x -> saldo += 35;
		printf("\tApuesta: $%d\n", x -> dinero);  
	}
	else{
		printf("\tDerrota, Numero ganador: %d\n",casilla_elegida);	
		x -> perdidos += 1; 
		x -> saldo -= x -> dinero;
		x -> dinero = 0;
		printf("\tApuesta: $%d\n", x -> dinero);
	}

	x -> jugados += 1;
	return x;
}

Partida numerosRojos(Circular c, Elem cero, Partida x){
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
		x -> saldo += 35;
		printf("\tApuesta: $%d\n", x -> dinero);  
	}
	else{
		printf("\tDerrota, Numero ganador: %d\n",casilla_elegida);	
		x -> perdidos += 1; 
		x -> saldo -= x -> dinero;
		x -> dinero = 0;
		printf("\tApuesta: $%d\n", x -> dinero);
	}

	x -> jugados += 1;
	return x;
}

Partida numerosNegros(Circular c, Elem cero, Partida x){
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
		x -> saldo += 35;
		printf("\tApuesta: $%d\n", x -> dinero);  
	}
	else{
		printf("\tDerrota, Numero ganador: %d\n",casilla_elegida);	
		x -> perdidos += 1; 
		x -> saldo -= x -> dinero;
		x -> dinero = 0;
		printf("\tApuesta: $%d\n", x -> dinero);
	}

	x -> jugados += 1;
	return x;
}