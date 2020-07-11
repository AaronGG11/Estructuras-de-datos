
typedef struct Nodo{
	int index;
	Elem dato;
	struct Nodo * anterior;
	struct Nodo * siguiente;
} * ApNodo;

typedef struct BNodo{
	ApNodo entrada;
	ApNodo salida;
} * Bicola;


Bicola nuevaB(){
	Bicola temporal = (Bicola)malloc(sizeof(struct BNodo));
	temporal -> salida = temporal -> entrada = NULL;
	return temporal;
}

int esNuevaB(Bicola b){
	return ((b -> salida == NULL)&&(b -> entrada == NULL));
}

Bicola formarI(Elem e, Bicola b){
	ApNodo temporal = (ApNodo)malloc(sizeof(struct Nodo));
	temporal -> dato = e;
	temporal -> anterior = NULL;

	if(esNuevaB(b)){
		b -> entrada = b -> salida = temporal;
		b -> entrada -> index = 1;
		temporal -> siguiente = NULL;
	}
	else{
		temporal -> index = b -> entrada -> index + 1;
		temporal -> siguiente = b -> entrada;
		b -> entrada = b -> entrada -> anterior = temporal;
	}
	return b;
}

Bicola formarD(Bicola b, Elem e){
	ApNodo temporal = (ApNodo)malloc(sizeof(struct Nodo));
	temporal -> dato = e;
	temporal -> siguiente = NULL;

	if(esNuevaB(b)){
		b -> entrada = b -> salida = temporal;
		temporal -> anterior = NULL;
	}
	else{
		temporal -> anterior = b -> salida;
		b -> salida = b -> salida -> siguiente = temporal;
	}
	return b;
}

Bicola desformarI(Bicola b){
	if(b -> entrada == b -> salida) // cuando hay un solo elemento
		b -> entrada = b -> salida = NULL;
	else{
		b -> entrada = b -> entrada -> siguiente;
		b -> entrada -> anterior = NULL;
	}
	return b;
}

Bicola desformarD(Bicola b){
	if(b -> entrada == b -> salida) // cuando hay un solo elemento
		b -> entrada = b -> salida = NULL;
	else{
		b -> salida = b -> salida -> anterior;
		b -> salida -> siguiente = NULL;
	}
	return b;
}

Elem primeroI(Bicola b){
	return b -> entrada -> dato;
}

Elem primeroD(Bicola b){
	return b -> salida -> dato;
}

void ImpBicolaI_clase	(Bicola b){
	ApNodo t = (ApNodo)malloc(sizeof(struct Nodo));
	t = b -> entrada;
	while(t!=NULL){
		ImpElem(t->dato);
		t = t -> siguiente;
	}
	printf("\n"); //
}

void ImpBicolaI_index(Bicola b){
	ApNodo t = (ApNodo)malloc(sizeof(struct Nodo));
	t = b -> entrada;
	while(t!=NULL){
		ImpElem(t->index);
		t = t -> siguiente;
	}
	printf("\n"); //
}

void ImpBicolaI_index_clase(Bicola b){
	ApNodo t = (ApNodo)malloc(sizeof(struct Nodo));
	t = b -> entrada;
	while(t!=NULL){
		ImpElem(t->index);
		ImpElem(t->dato);
		printf("\n");
		t = t -> siguiente;
	}
	printf("\n"); //
}

void ImpBicolaD_clase(Bicola b){
	ApNodo t = (ApNodo)malloc(sizeof(struct Nodo));
	t = b -> salida;
	while(t!=NULL){
		ImpElem(t->dato);
		t = t -> anterior;
	}
}

Bicola ImpBicolaI_clase_crea(Bicola b){ //segun yo, no tiene mucha razon de ser, *** checarla
	Bicola temporal = (Bicola)malloc(sizeof(struct BNodo));
	temporal = nuevaB();

	while(!esNuevaB(b)){
		ImpElem(primeroI(b));
		temporal=formarD(temporal,primeroI(b));
		b = desformarI(b);
	}
	return b;
}

void ImpBicolaI_Rec(Bicola b){
	Bicola temporal = nuevaB();
	temporal -> entrada = b -> entrada;
	temporal -> salida = b -> salida;

	if(!esNuevaB(temporal)){
		ImpElem(primeroI(temporal));
		ImpBicolaI_Rec(desformarI(temporal));
	}
}

