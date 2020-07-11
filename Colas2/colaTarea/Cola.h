
typedef struct Nodo{
		Elem dato;
		struct Nodo * siguiente;
} *ApNodo;

typedef struct CNodo{
	ApNodo salida;
	ApNodo entrada;
} *Cola;


Cola nueva(){
	Cola temporal = (Cola)malloc(sizeof(struct CNodo));
	temporal -> entrada = temporal -> salida = NULL;
	return temporal;
}

int esNueva(Cola q){
	return (q -> salida == NULL) && (q -> entrada = NULL);
}

Elem primero(Cola q){
	return q -> salida -> dato;
}

Cola formar(Cola q, Elem e){
	ApNodo temporal = (ApNodo)malloc(sizeof(struct Nodo));
	temporal -> dato = e;

	if(esNueva(q)){
		q -> salida = q -> entrada = temporal;
		temporal -> siguiente = NULL;
	}
	else{
		q -> entrada -> siguiente = q -> entrada = temporal;
		temporal -> siguiente = NULL;
	}
	return q;
}


Cola desformar(Cola q){
	if(esNueva(q))
		return nueva();
	else{
		q -> salida = q -> salida -> siguiente;
		return q;
	}
}

void ImpCola(Cola q){
	Cola temporal = nueva();
	temporal -> entrada = q -> entrada;
	temporal -> salida = q -> salida;

	if((q -> salida) == (q -> entrada))
		printf("Cola vacia\n");
	else{
		ImpElem(primero(temporal));
		ImpCola(desformar(temporal));
	}
}




