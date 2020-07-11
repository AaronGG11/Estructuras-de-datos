

typedef struct NodoL{
	ElemHT dato;
	struct NodoL * siguiente;
} * Lista;

Lista Vacia(){
	return NULL;
}

// Construye un nodo 
Lista Cons(ElemHT e, Lista l){ 
	Lista auxiliar = (Lista)malloc(sizeof(struct NodoL));
	auxiliar -> dato = e;
	auxiliar -> siguiente = l;
	return auxiliar;
}

// Verifica si esta vacia la lista
int esVacia(Lista l){
	return l == Vacia(); // 0 si es falso, 1 distinto de 0
}

// Obtiene la cabeza de la lista
ElemHT Cabeza(Lista l){
	return l -> dato;
}

// Obtiene el resto de la lista
Lista Resto(Lista l){
	return l -> siguiente;	
}

// Cuenta el numero de nodos/elementos de la lista
int NumElem(Lista l){
	if(esVacia(l)){
		return 0;
	}
	else{
		return 1 + NumElem(Resto(l));
	}
}


// Inserta en orden un elemento a la lista
Lista InsOrd(ElemHT e, Lista l){
	if(esVacia(l)){
		return Cons(e,l);
	}
	else if(esMenor(e,Cabeza(l))){
		return Cons(e,l);
	}
	else{
		return Cons(Cabeza(l),InsOrd(e,Resto(l)));
	}
}

// Funcion que ordena una lista de manera ascendente 
Lista OrdLista(Lista l){
	if(esVacia(l)){
		return l;
	}
	else{
		return InsOrd(Cabeza(l),OrdLista(Resto(l)));
	}
}

/*
// Funcion que ordena una lista de manera descendente
Lista OrdListaDes(Lista l){
	return InvierteLista(OrdLista(l));
}
*/



Lista PegaListas(Lista x, Lista y){
	if(esVacia(x)){
		return y;
	}
	else{
		return Cons(Cabeza(x),PegaListas(Resto(x),y));
	}
}



















