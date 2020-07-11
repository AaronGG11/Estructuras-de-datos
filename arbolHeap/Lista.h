

typedef struct NodoL{
	Elem dato;
	struct NodoL * siguiente;
} * Lista;

Lista Vacia(){
	return NULL;
}

// Construye un nodo 
Lista ConsL(Elem e, Lista l){ 
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
Elem Cabeza(Lista l){
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

// imprime la lista
void ImpLista(Lista l){
	if(!esVacia(l)){
		impElem(Cabeza(l));
		ImpLista(Resto(l));
	}
}

// Une dos listas
Lista PegaListas(Lista x, Lista y){
	if(esVacia(x)){
		return y;
	}
	else{
		return ConsL(Cabeza(x),PegaListas(Resto(x),y));
	}
}

// Invierte una lista
Lista InvierteLista(Lista l){
	if(esVacia(l)){
		return l;
	}
	else{
		return PegaListas(InvierteLista(Resto(l)),ConsL(Cabeza(l),Vacia()));
	}
}

// Multiplica por 3, la lista, solo con enteros
/*
Lista MultxN(Lista l){

	int factor = 3;

	if(esVacia(l)){
		return l;
	}
	else{
		return Cons(Cabeza(l)*factor,MultxN(Resto(l)));
	}
}
*/


// Ingresa elementos a la lista de manera continua, hasta que el ususario lo decida, solo con enteros
/*
Lista LeeLista(){
	Lista l = Vacia();
	int num;
	char control = 's';


	while((control == 's')||(control == 'S')){
		printf("Teclea un elemento: ");
		scanf("%d", &num);
		l=Cons(num,l);
		LimpiaBuffer();
		printf("Ingresar otro elemento[S/N]: ");
		scanf("%c", &control);
	}
	return l;
}
*/

// Inserta en orden un elemento a la lista
Lista InsOrd(Elem e, Lista l){
	if(esVacia(l)){
		return ConsL(e,l);
	}
	else if(esMenor(e,Cabeza(l))){
		return ConsL(e,l);
	}
	else{
		return ConsL(Cabeza(l),InsOrd(e,Resto(l)));
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

// Funcion que ordena una lista de manera descendente
Lista OrdListaDes(Lista l){
	return InvierteLista(OrdLista(l));
}

/* definir una fucnion que reciba como argumento un elemto y una lista
	y devuelve verdadero si el elemento esta en la lista o falso en caso contrario*/
int estaEn(Elem e, Lista l){
	if(esVacia(l)){
		return 0;
	}
	else if(sonIguales(e,Cabeza(l))){
		return 1;
	}
	else{
		return estaEn(e,Resto(l));
	}
}






















