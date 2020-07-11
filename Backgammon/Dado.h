
typedef struct dado{
	int dado_1;
	int dado_2;
	int dado_1_2;
	int dado_2_2;
} * Dados;

Dados nuevosDados(){
	Dados temporal = (Dados)malloc(sizeof(struct dado));
	temporal -> dado_1 = 0;
	temporal -> dado_2 = 0;
	temporal -> dado_1_2 = 0;
	temporal -> dado_2_2 = 0;
	return temporal;
}

Dados tirarDados(){

	Dados d = nuevosDados();
	
	d -> dado_1 = 1 + rand()%6;
	d -> dado_2 = 1 + rand()%6;

	if(d->dado_1 == d->dado_2)
		d -> dado_1_2 = d -> dado_2_2 = d -> dado_1;
	else
		d -> dado_1_2 = d -> dado_2_2 = 0;
	
	return d;
}

void impDados_turno(Dados d){
		printf("\n\t---------     ---------");
		printf("\n\t|       |     |       |");
		printf("\n\t|   %d   |     |   %d   |", d -> dado_1, d -> dado_2);
		printf("\n\t|       |     |       |");
		printf("\n\t---------     ---------");
		printf("\n\n");
}

void impDados(Dados d){
	if(d -> dado_1_2 == 0){
		printf("\t---------     ---------");
		printf("\n\t|       |     |       |");
		printf("\n\t|   %d   |     |   %d   |", d -> dado_1, d -> dado_2);
		printf("\n\t|       |     |       |");
		printf("\n\t---------     ---------");
		printf("\n\n");
	}
	else{
		printf("\n\t---------     ---------     ---------     ---------");
		printf("\n\t|       |     |       |     |       |     |       |");
		printf("\n\t|   %d   |     |   %d   |     |   %d   |     |   %d   |", d -> dado_1, d -> dado_2, d->dado_1_2, d->dado_2_2);
		printf("\n\t|       |     |       |     |       |     |       |");
		printf("\n\t---------     ---------     ---------     ---------");
		printf("\n\n");
	}
}

int sonIgualesTiros(Jugador x, Jugador y){
	return x -> suma_dados == y -> suma_dados;
}


int esMayor(Jugador x, Jugador y){
	return x -> suma_dados > y -> suma_dados;
}

int sonDadosDobles(Dados d){
	if((d -> dado_1 == d -> dado_2)&&(d->dado_1_2+d->dado_2_2>0))
		return 1;
	else 
		return 0;
}

int sumarDados(Dados d){
	return (d->dado_1+d->dado_2+d->dado_1_2+d->dado_2_2); 
}

int sonDadosDoblesMitad(Dados d){
	if((d -> dado_1 == d -> dado_2)&&(d->dado_1_2+d->dado_2_2== 0))
		return 1;
	else 
		return 0;
}




