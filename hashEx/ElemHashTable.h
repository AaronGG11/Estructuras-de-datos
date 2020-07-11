
typedef char * String;

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

int valueOf(String s){
	int value = 0;

	for(int i=0; i<strlen(s); i++){
		value += s[i];
	}

	return value;
}

int valueHash(int x, int n){ // valor de string, tamanio final de la tabla
	return (x%n);
}

int sonIguales(int x, int y){
	return x == y;
}

int esMenor(int x, int y){
	return x < y;
}

int esMayor(int x, int y){
	return x > y;
}

int sonLasMismas(String a, String b){
	return strcasecmp(a,b) == 0;
}

int esMenorString(String a, String b){
	return strcasecmp(a,b) < 0;
}

int esMayorString(String a, String b){
	return strcasecmp(a,b) > 0;
}

ElemHT nuevoElemento(){
	ElemHT e;
	
	e.nombre   = (String)malloc(sizeof(20));
	e.simbolo  = (String)malloc(sizeof(5));
	e.inventor = (String)malloc(sizeof(20));
	e.fecha    = (String)malloc(sizeof(15));
	e.grupo    = (String)malloc(sizeof(5));

	return e;
}

void impElemHT(ElemHT e){
	printf("\n\n\tNumero atomico: %d \n\tNombre: %s \n\tSimbolo: %s \n\tPeriodo: %d "
		"\n\tGrupo: %s \n\tMasa Atomica: %.2f \n\tFecha: %s \n\tInventor: %s\n\n", e.numAtomico,
		 e.nombre, e.simbolo, e.periodo, e.grupo, e.masaAtomica, e.fecha, e.inventor);
}





