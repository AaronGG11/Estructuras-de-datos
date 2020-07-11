typedef struct Nodo{
	Elem dato;
	struct Nodo * siguiente;
} *Circular;

Circular nuevaC(){
	return NULL;
}

int esNuevaC(Circular q){
	return q == NULL;
}

Circular formarC(Circular q, Elem e){
	Circular temporal = (Circular)malloc(sizeof(struct Nodo));
	temporal -> dato = e;
	if(esNuevaC(q)){
		q = temporal;
		q -> siguiente = q;
	}
	else{
		temporal -> siguiente = q -> siguiente;
		q -> siguiente = temporal;
	}
	return temporal;
}

Elem primeroC(Circular q){
	return q -> siguiente -> dato;
}

Circular desformarC(Circular q){
	Circular temporal = (Circular)malloc(sizeof(struct Nodo)); //
	if(q == q->siguiente)
		return nuevaC();
	else{
		temporal = q -> siguiente;
		q -> siguiente = q->siguiente->siguiente;
		free(temporal);
		return q;
	}
}

Circular rotar(Circular q){
	return q -> siguiente;
}

/*
void ImpColaC(Circular q){
	ImpElem(primeroC(q));
	q = rotar(q);
	getchar();

	ImpColaC(q);
}
*/


