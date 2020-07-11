 
typedef struct Nodo{
	Elem raiz;
	struct Nodo * izquierdo;
	struct Nodo * derecho; 
} * ArBin;

ArBin vacio(){
	return NULL;
}

ArBin consA(Elem r, ArBin i, ArBin d){
	ArBin  temporal = (ArBin)malloc(sizeof(struct Nodo));
	temporal -> raiz = r ;
	temporal -> izquierdo = i;
	temporal -> derecho = d;
	return temporal;
}

int esVacio(ArBin a){
	return a == vacio();
}

Elem raiz(ArBin a){
	return a -> raiz;
}

ArBin izq(ArBin a){
	return a -> izquierdo;
}

ArBin der(ArBin a){
	return a -> derecho;
}

int numElem(ArBin a){
	if(esVacio(a))
		return 0;
	else{
		return 1 + numElem(izq(a)) + numElem(der(a));
	}
}

// Formas de recorrer un arbol 
void inOrd(ArBin a){ // izquierdo, raiz, derecho
	if(!esVacio(a)){
		inOrd(izq(a));
		impElem(raiz(a));
		inOrd(der(a));
	}
}

void preOrd(ArBin a){ // raiz, izquierdo, derecho
	if(!esVacio(a)){
		impElem(raiz(a));
		preOrd(izq(a));
		preOrd(der(a));
	}
}

void posTorDer(ArBin a){ // izquierdo, derecho, raiz
	if(!esVacio(a)){
		posTorDer(izq(a));
		posTorDer(der(a));
		impElem(raiz(a));
	}
}

int maximo(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}

int alturaArbol(ArBin a){
	if(esVacio(a))
		return 0;
	else
		return 1 + maximo(alturaArbol(izq(a)),alturaArbol(der(a)));
}

int esHoja(ArBin a){
	return esVacio(izq(a))&&esVacio(der(a));
}

int esInterno(ArBin a){
	return (!esHoja(a));
}

int nivel(ArBin a){
	return alturaArbol(a)-1;
}


// un nodo que no tiene hijos se le llama hoja
// interior es que no es una hoja 


// arbol con prioridades


