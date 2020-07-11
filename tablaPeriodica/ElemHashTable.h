
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

int getKey(ElemHT e){
	return e.numAtomico;
}

int getKeyHT(ElemHT e, int n){
	return getKey(e)%numPrimoSig(n);
}

int sonIguales(int m, int n){
	return n == m;
}

int esMenor(ElemHT x, ElemHT y){
	return x.numAtomico < y.numAtomico;
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






