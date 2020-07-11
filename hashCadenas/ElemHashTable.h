
typedef char* String;

typedef struct tp{
	int numAtomico;
	String nombre;
	String simbolo;
	int periodo;
	String grupo;
	float masaAtomica;
	String fecha;
	String inventor;
} ElemHT;


int esNumPrimo(int n){
	int c = 0;

	for(int i = 1; i<=n; i++){
		if(n%i == 0)
			c++;
	}

	if(c == 2)
		return 1;
	else
		return 0;
}

int numPrimoSig(int n){
	if(esNumPrimo(n))
		return n;
	else
		return numPrimoSig(n+1);
}



String getNombre(ElemHT e){
	return e.nombre;
}

int valorString(String cadena){
	int valor = 0;
	for(int i=0; i<strlen(cadena); i++){
		valor += cadena[i];
	}
	return valor;
}

int getKey(ElemHT e, int n){ // elemento y tamaño propuesto de la hash 
	return (valorString(getNombre(e)))%numPrimoSig(n);
}

int sonIgualesNumeros(int m, int n){
	return n == m;
}

int sonIgualesCadenas(String m, String n){
	return strcasecmp(m,n);
}


int esMenor(ElemHT x, ElemHT y){
	return strcasecmp(getNombre(x),getNombre(y)) < 0;
}

ElemHT nuevoElemento(){
	ElemHT e;
	
	e.nombre = (String)malloc(sizeof(20));
	e.simbolo = (String)malloc(sizeof(5));
	e.inventor = (String)malloc(sizeof(20));
	e.fecha = (String)malloc(sizeof(15));
	e.grupo = (String)malloc(sizeof(5));

	return e;
}

void impElemHT(ElemHT e){
	printf("\n\nNumero atomico: %d \nNombre: %s \nSimbolo: %s \nPeriodo: %d "
		"\nGrupo: %s \nMasa Atomica: %.2f \nFecha: %s \nInventor: %s\n\n", e.numAtomico, e.nombre, e.simbolo,
			e.periodo, e.grupo, e.masaAtomica, e.fecha, e.inventor);
}






