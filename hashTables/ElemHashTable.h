
typedef struct tp{
	int id;
	char * nombre;
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
	return e.id;
}

int getKeyHT(ElemHT e, int n){
	return getKey(e)%numPrimoSig(n);
}

int sonIguales(int m, int n){
	return n == m;
}

int esMenor(ElemHT x, ElemHT y){
	return x.id < y.id;
}








